import math
import random

random.seed(42)

# =====================================================================
# 🎫 PHASE 1: VOCABULARY & TOKENIZER PIPELINE
# =====================================================================
training_data = "Hello world! i  am learning to build an ai model from the stratch."
vocabulary = sorted(list(set(training_data)))
vocab_size = len(vocabulary)  # 22 unique characters

stringtointeger = {ch: idx for idx, ch in enumerate(vocabulary)}
integertostring = {idx: ch for idx, ch in enumerate(vocabulary)}


def encode(text):
    return [stringtointeger[ch] for ch in text if ch in stringtointeger]


def decode(token_ids):
    return "".join([integertostring[idx] for idx in token_ids if idx in integertostring])


# =====================================================================
# 🛠️ PHASE 2: GPT-STYLE SLIDING DATASET GENERATOR
# =====================================================================
def create_dataset_batches(text_data, block_size):
    """
    Generates all valid (X, Y) training pairs across the text stream.
    For every position, Y is the next character that follows X.
    """
    token_ids = encode(text_data)
    dataset = []

    # Slide a window of length (block_size + 1) across the entire stream
    for i in range(len(token_ids) - block_size):
        chunk = token_ids[i : i + block_size + 1]
        x = chunk[:-1]
        y = chunk[1:]
        dataset.append((x, y))

    return dataset


# =====================================================================
# 🔲 PHASE 3: THE MODEL ARCHITECTURE (Embeddings -> Linear -> Softmax)
# =====================================================================
embedding_dim = 8  # 8 latent features per character

# 1. Embedding lookup table: [vocab_size, embedding_dim]
embedding_matrix = [
    [round(random.uniform(-0.5, 0.5), 4) for _ in range(embedding_dim)]
    for _ in range(vocab_size)
]

# 2. Linear projection layer weights: [embedding_dim, vocab_size]
# Notice: out_features == vocab_size (22), eliminating any index-clamping hacks!
weights = [
    [round(random.uniform(-0.5, 0.5), 4) for _ in range(vocab_size)]
    for _ in range(embedding_dim)
]

# 3. Bias vector: [vocab_size]
bias = [0.0] * vocab_size


def get_embeddings(token_ids):
    return [embedding_matrix[tid] for tid in token_ids]


def matrix_mul(m1, m2):
    r1, c1 = len(m1), len(m1[0])
    c2 = len(m2[0])
    mul = [[0.0] * c2 for _ in range(r1)]
    for i in range(r1):
        for j in range(c2):
            mul[i][j] = sum(m1[i][k] * m2[k][j] for k in range(c1))
    return mul


def forward_pass(token_ids):
    """
    Complete forward inference:
    Tokens -> Embeddings -> Linear Projection -> Softmax Probabilities
    """
    # [T, embedding_dim]
    x_embed = get_embeddings(token_ids)

    # [T, vocab_size] = [T, embedding_dim] x [embedding_dim, vocab_size]
    logits = matrix_mul(x_embed, weights)

    # Add bias
    for i in range(len(logits)):
        for j in range(vocab_size):
            logits[i][j] += bias[j]

    # Numerically stable Softmax
    probs = []
    for row in logits:
        max_val = max(row)
        exp_row = [math.exp(val - max_val) for val in row]
        sum_exp = sum(exp_row)
        probs.append([e / sum_exp for e in exp_row])

    return logits, probs


# =====================================================================
# 📉 PHASE 4: CROSS-ENTROPY LOSS & METRICS ENGINE
# =====================================================================
def compute_cross_entropy_loss(softmax_probs, target_token_ids, verbose=True):
    """
    Calculates Cross-Entropy Loss and Perplexity without clamping or truncation.
    Formula:
        Loss = -ln(P_target)
        Perplexity = exp(Average_Loss)
    """
    total_loss = 0.0
    num_tokens = len(target_token_ids)

    if verbose:
        print("\n" + "-" * 92)
        print(" 🔍 DETAILED LOSS ENGINE BREAKDOWN (Char-by-Char Confidence)")
        print("-" * 92)

    for i in range(num_tokens):
        target_idx = target_token_ids[i]
        true_char = integertostring[target_idx]

        # Target probability directly retrieved from the 22-class probability distribution
        p_target = max(softmax_probs[i][target_idx], 1e-15)  # Epsilon prevents log(0)
        token_loss = -math.log(p_target)
        total_loss += token_loss

        # Network's current best guess
        predicted_idx = softmax_probs[i].index(max(softmax_probs[i]))
        predicted_char = integertostring[predicted_idx]
        is_match = "✅" if predicted_idx == target_idx else "❌"

        if verbose:
            print(
                f" Pos {i:02d} | Target: '{true_char}' (ID: {target_idx:02d}) | "
                f"Model Guessed: '{predicted_char}' {is_match} | "
                f"P(Target): {p_target * 100:6.2f}% | Step Loss: {token_loss:.4f}"
            )

    avg_loss = total_loss / num_tokens
    perplexity = math.exp(avg_loss)

    return avg_loss, perplexity


# =====================================================================
# 🚀 END-TO-END DEMONSTRATION
# =====================================================================
if __name__ == "__main__":
    print("=" * 92)
    print("       🚀 AUTOREGRESSIVE LANGUAGE MODEL TRAINING & LOSS ENGINE (PURE PYTHON)")
    print("=" * 92)
    print(f"Vocabulary Size: {vocab_size} characters -> {repr(''.join(vocabulary))}\n")

    # 1. Generate Context Windows
    context_window = 6
    batches = create_dataset_batches(training_data, block_size=context_window)
    print(f"Total Training Windows Generated from text: {len(batches)}")

    # Pick the first batch window to inspect
    sample_x, sample_y = batches[0]
    print(f"Context Input   (X): {sample_x} -> \"{decode(sample_x)}\"")
    print(f"Next Target Char(Y): {sample_y} -> \"{decode(sample_y)}\"")

    # 2. Run Forward Pass
    logits, probabilities = forward_pass(sample_x)

    # 3. Compute Loss and Perplexity
    loss, perp = compute_cross_entropy_loss(probabilities, sample_y, verbose=True)

    # Theoretical random baseline loss = -ln(1 / vocab_size)
    baseline_loss = -math.log(1.0 / vocab_size)

    print("\n" + "=" * 92)
    print(" 📊 EVALUATION METRICS SUMMARY")
    print("=" * 92)
    print(f" • Average Cross-Entropy Loss : {loss:.4f}")
    print(f" • Baseline (Uniform Random)   : {baseline_loss:.4f}")
    print(f" • Model Perplexity (PPL)      : {perp:.2f} (equivalent to guessing out of {perp:.1f} options)")
    print("=" * 92)