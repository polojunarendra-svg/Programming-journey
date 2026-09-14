import math
import random

random.seed(42)

# =====================================================================
# 1. TOKENIZER & VOCABULARY SETUP
# =====================================================================
corpus = "Hello world! i am learning to build an ai model from scratch."
vocabulary = sorted(list(set(corpus)))
vocab_size = len(vocabulary)

char2idx = {ch: i for i, ch in enumerate(vocabulary)}
idx2char = {i: ch for i, ch in enumerate(vocabulary)}


def encode(text):
    return [char2idx[ch] for ch in text if ch in char2idx]


def decode(indices):
    return "".join([idx2char[idx] for idx in indices if idx in idx2char])


# =====================================================================
# 2. MATRIX MATH ENGINE (Pure Python)
# =====================================================================
def matrix_mul(A, B):
    rA, cA = len(A), len(A[0])
    rB, cB = len(B), len(B[0])
    assert cA == rB, f"Shape mismatch: {cA} != {rB}"
    C = [[0.0] * cB for _ in range(rA)]
    for i in range(rA):
        for j in range(cB):
            C[i][j] = sum(A[i][k] * B[k][j] for k in range(cA))
    return C


def transpose(A):
    return [[A[i][j] for i in range(len(A))] for j in range(len(A[0]))]


def add_matrices(A, B):
    return [[A[i][j] + B[i][j] for j in range(len(A[0]))] for i in range(len(A))]


def layer_norm(X, eps=1e-5):
    """Normalizes features across the embedding dimension."""
    normed = []
    d_model = len(X[0])
    for row in X:
        mean = sum(row) / d_model
        var = sum((x - mean) ** 2 for x in row) / d_model
        std = math.sqrt(var + eps)
        normed.append([(x - mean) / std for x in row])
    return normed


def softmax(matrix):
    probs = []
    for row in matrix:
        max_val = max(row)
        exp_row = [math.exp(v - max_val) for v in row]
        sum_exp = sum(exp_row)
        probs.append([e / sum_exp for e in exp_row])
    return probs


# =====================================================================
# 3. TRANSFORMER HYPERPARAMETERS & WEIGHT INITIALIZATION
# =====================================================================
d_model = 8  # Embedding & hidden dimensions
d_ff = 16  # Feed-Forward expansion dimension
block_size = 12  # Maximum context window length


def init_matrix(rows, cols, scale=0.2):
    return [[round(random.uniform(-scale, scale), 4) for _ in range(cols)] for _ in range(rows)]


# Embedding Tables
token_embeddings = init_matrix(vocab_size, d_model)
position_embeddings = init_matrix(block_size, d_model)

# Causal Self-Attention Weights
W_q = init_matrix(d_model, d_model)
W_k = init_matrix(d_model, d_model)
W_v = init_matrix(d_model, d_model)
W_out = init_matrix(d_model, d_model)

# Feed-Forward Network Weights (MLP)
W_ff1 = init_matrix(d_model, d_ff)
W_ff2 = init_matrix(d_ff, d_model)

# Output Language Model Head
W_head = init_matrix(d_model, vocab_size)


# =====================================================================
# 4. FORWARD PASS THROUGH THE FULL LLM BLOCK
# =====================================================================
def transformer_forward(input_tokens):
    T = len(input_tokens)
    assert T <= block_size, "Context length exceeds block_size"

    # Step 1: Token + Positional Embeddings
    X = []
    for pos, token_id in enumerate(input_tokens):
        tok_vec = token_embeddings[token_id]
        pos_vec = position_embeddings[pos]
        combined = [tok_vec[k] + pos_vec[k] for k in range(d_model)]
        X.append(combined)

    # Step 2: Causal Self-Attention
    # Pre-LN
    X_norm1 = layer_norm(X)

    Q = matrix_mul(X_norm1, W_q)
    K = matrix_mul(X_norm1, W_k)
    V = matrix_mul(X_norm1, W_v)

    # Scaled Dot-Product Attention: (Q x K^T) / sqrt(d_k)
    K_T = transpose(K)
    scores = matrix_mul(Q, K_T)
    scale = 1.0 / math.sqrt(d_model)
    for i in range(T):
        for j in range(T):
            scores[i][j] *= scale
            if j > i:  # Causal mask: forbid looking at future tokens
                scores[i][j] = -1e9

    attn_weights = softmax(scores)
    context = matrix_mul(attn_weights, V)
    attn_out = matrix_mul(context, W_out)

    # Residual Connection 1
    X_residual1 = add_matrices(X, attn_out)

    # Step 3: Feed-Forward Network (FFN)
    # Pre-LN
    X_norm2 = layer_norm(X_residual1)

    # Linear 1 + ReLU Activation
    hidden_ff = matrix_mul(X_norm2, W_ff1)
    hidden_relu = [[max(0.0, val) for val in row] for row in hidden_ff]

    # Linear 2 (Projection back to d_model)
    ffn_out = matrix_mul(hidden_relu, W_ff2)

    # Residual Connection 2
    X_final = add_matrices(X_residual1, ffn_out)

    # Step 4: Final LM Head Projection -> Logits & Softmax Probabilities
    X_norm_final = layer_norm(X_final)
    logits = matrix_mul(X_norm_final, W_head)
    probabilities = softmax(logits)

    return attn_weights, probabilities


# =====================================================================
# 5. GENERATION & VISUALIZATION
# =====================================================================
def run_llm_step(prompt_text):
    tokens = encode(prompt_text)
    print("=" * 78)
    print(f" INPUT PROMPT: '{prompt_text}' | TOKENS: {tokens}")
    print("=" * 78)

    attn_weights, probs = transformer_forward(tokens)

    # 1. Render Causal Attention Heatmap
    print("\n1. CAUSAL ATTENTION MATRIX (How tokens attend to each other):")
    header = "       " + " ".join([f"'{ch}':" for ch in prompt_text])
    print(header)
    for i, row in enumerate(attn_weights):
        row_str = " ".join([f"{val * 100:5.1f}%" for val in row])
        print(f"'{prompt_text[i]}':  [{row_str}]")

    # 2. Inspect Prediction for the next character
    next_token_probs = probs[-1]
    top_prediction_idx = next_token_probs.index(max(next_token_probs))
    pred_char = idx2char[top_prediction_idx]
    confidence = next_token_probs[top_prediction_idx] * 100

    print(f"\n2. AUTOREGRESSIVE PREDICTION FOR NEXT CHARACTER:")
    print(f" • Input Sequence     : '{prompt_text}'")
    print(f" • Predicted Next Char: '{pred_char}'")
    print(f" • Model Confidence   : {confidence:.2f}%")


if __name__ == "__main__":
    run_llm_step("Hello")