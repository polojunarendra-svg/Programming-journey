import math
import random
import time

random.seed(42)

# =====================================================================
# 1. DYNAMIC VOCABULARY & TOKENIZER (WITH <unk> FALLBACK)
# =====================================================================
# Base training universe
base_corpus = "Hello world! i am learning to build an ai model from scratch."
unique_chars = sorted(list(set(base_corpus)))

# Ensure unknown characters don't crash or misalign the pipeline
vocabulary = ["<unk>"] + unique_chars
vocab_size = len(vocabulary)

char2idx = {ch: i for i, ch in enumerate(vocabulary)}
idx2char = {i: ch for i, ch in enumerate(vocabulary)}


def encode(text):
    ids = []
    for ch in text:
        if ch in char2idx:
            ids.append(char2idx[ch])
        else:
            ids.append(char2idx["<unk>"])
    return ids


def decode(indices):
    return "".join([idx2char[i] if idx2char[i] != "<unk>" else "?" for i in indices])


# =====================================================================
# 2. MATRIX MATH & TRANSFORMER OPS
# =====================================================================
def matrix_mul(A, B):
    rA, cA = len(A), len(A[0])
    cB = len(B[0])
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
    normed = []
    d_model = len(X[0])
    for row in X:
        mean = sum(row) / d_model
        var = sum((x - mean) ** 2 for x in row) / d_model
        std = math.sqrt(var + eps)
        normed.append([(x - mean) / std for x in row])
    return normed


def softmax(row):
    max_val = max(row)
    exp_vals = [math.exp(v - max_val) for v in row]
    sum_exp = sum(exp_vals)
    return [v / sum_exp for v in exp_vals]


# =====================================================================
# 3. HYPERPARAMETERS & WEIGHT MATRICES
# =====================================================================
d_model = 4      # 4 features per token for readable ASCII wiring diagrams
d_ff = 6         # Feed-Forward expansion dimension
block_size = 24  # Maximum context window length


def init_matrix(rows, cols, scale=0.3):
    return [
        [round(random.uniform(-scale, scale), 4) for _ in range(cols)]
        for _ in range(rows)
    ]


token_embedding_table = init_matrix(vocab_size, d_model)
position_embedding_table = init_matrix(block_size, d_model)

W_q = init_matrix(d_model, d_model)
W_k = init_matrix(d_model, d_model)
W_v = init_matrix(d_model, d_model)
W_proj = init_matrix(d_model, d_model)

W_mlp1 = init_matrix(d_model, d_ff)
W_mlp2 = init_matrix(d_ff, d_model)

W_lm_head = init_matrix(d_model, vocab_size)


# =====================================================================
# 4. STEP-BY-STEP TERMINAL DIAGRAMS
# =====================================================================
def draw_embedding_stage(char, tok_id, pos, tok_vec, pos_vec, sum_vec):
    print(f"""
  ===========================================================================================
  STEP 1: EMBEDDINGS SUMMATION [Token '{char}' (ID: {tok_id}) at Position {pos:02d}]
  ===========================================================================================
    Token Embeddings (Word Identity)         Positional Embeddings (Word Order)      Combined Vector (Input X)
    ( O ) T_Dim 0: [{tok_vec[0]:>7.3f}] ───\\       ( O ) P_Dim 0: [{pos_vec[0]:>7.3f}] ───\\       ──> [X0]: {sum_vec[0]:>7.3f}
    ( O ) T_Dim 1: [{tok_vec[1]:>7.3f}] ───┼────── ( O ) P_Dim 1: [{pos_vec[1]:>7.3f}] ───┼──────> [X1]: {sum_vec[1]:>7.3f}
    ( O ) T_Dim 2: [{tok_vec[2]:>7.3f}] ───┼────── ( O ) P_Dim 2: [{pos_vec[2]:>7.3f}] ───┼──────> [X2]: {sum_vec[2]:>7.3f}
    ( O ) T_Dim 3: [{tok_vec[3]:>7.3f}] ───/       ( O ) P_Dim 3: [{pos_vec[3]:>7.3f}] ───/       ──> [X3]: {sum_vec[3]:>7.3f}
  ===========================================================================================""")


def draw_qkv_stage(x_vec, q_vec, k_vec, v_vec):
    print(f"""
  ===========================================================================================
  STEP 2: QUERY, KEY, & VALUE PROJECTIONS (Self-Attention Gateway)
  ===========================================================================================
    LayerNorm Input (4 Dim)                                     Projected Attention Spaces
    ( O ) In 0: [{x_vec[0]:>7.3f}] ────\\ 
    ( O ) In 1: [{x_vec[1]:>7.3f}] ──────X──[ W_Q, W_K, W_V ]───> ( Q ) Query : [{q_vec[0]:>6.2f}, {q_vec[1]:>6.2f}, {q_vec[2]:>6.2f}, {q_vec[3]:>6.2f}]
    ( O ) In 2: [{x_vec[2]:>7.3f}] ──────X──────────────────────> ( K ) Key   : [{k_vec[0]:>6.2f}, {k_vec[1]:>6.2f}, {k_vec[2]:>6.2f}, {k_vec[3]:>6.2f}]
    ( O ) In 3: [{x_vec[3]:>7.3f}] ────/                         > ( V ) Value : [{v_vec[0]:>6.2f}, {v_vec[1]:>6.2f}, {v_vec[2]:>6.2f}, {v_vec[3]:>6.2f}]
  ===========================================================================================""")


def draw_attention_weights_stage(context_chars, current_char, attn_weights_row):
    print(f"""
  ===========================================================================================
  STEP 3: CAUSAL ATTENTION CONTEXT GATHERING [Reading: '{current_char}']
  ===========================================================================================""")
    for i, c in enumerate(context_chars):
        pct = attn_weights_row[i] * 100
        bars = "█" * max(1, int(pct / 5)) if pct > 0.0 else ""
        print(f"    ( O ) Prior Char '{c}' (Pos {i:02d}) ──────> Weight: {pct:>5.1f}% | {bars}")
    print("  ===========================================================================================")


def draw_feed_forward_stage(in_vec, h_relu, out_vec):
    print(f"""
  ===========================================================================================
  STEP 4: FEED-FORWARD NETWORK (MLP Knowledge Layer: 4 In -> 6 Hidden ReLU -> 4 Out)
  ===========================================================================================
    Attention+Resid (4 Dim)       Hidden Neurons (ReLU Clamped)              FFN Output Vector
    ( O ) In 0: [{in_vec[0]:>6.2f}] ───\\       ( O ) H0: [{h_relu[0]:>6.2f}] ───\\
    ( O ) In 1: [{in_vec[1]:>6.2f}] ─────X───> ( O ) H1: [{h_relu[1]:>6.2f}] ─────X────> ( O ) Out 0: [{out_vec[0]:>6.2f}]
    ( O ) In 2: [{in_vec[2]:>6.2f}] ─────X───> ( O ) H2: [{h_relu[2]:>6.2f}] ─────X────> ( O ) Out 1: [{out_vec[1]:>6.2f}]
    ( O ) In 3: [{in_vec[3]:>6.2f}] ───/       ( O ) H3: [{h_relu[3]:>6.2f}] ─────X────> ( O ) Out 2: [{out_vec[2]:>6.2f}]
                                               ( O ) H4: [{h_relu[4]:>6.2f}] ─────X────> ( O ) Out 3: [{out_vec[3]:>6.2f}]
                                               ( O ) H5: [{h_relu[5]:>6.2f}] ───/
  ===========================================================================================""")


def draw_final_output_gate(final_hidden, top_tokens, winner_char):
    h0, h1, h2, h3 = [round(x, 3) for x in final_hidden]
    c0, l0, p0 = top_tokens[0]
    c1, l1, p1 = top_tokens[1]
    c2, l2, p2 = top_tokens[2]
    c3, l3, p3 = top_tokens[3]

    w0 = " ★ Chosen Next Token" if c0 == winner_char else ""
    w1 = " ★ Chosen Next Token" if c1 == winner_char else ""
    w2 = " ★ Chosen Next Token" if c2 == winner_char else ""
    w3 = " ★ Chosen Next Token" if c3 == winner_char else ""

    print(f"""
  ===========================================================================================
  STEP 5: FINAL LM HEAD DECISION GATE (Softmax Distribution over Vocabulary)
  ===========================================================================================
    Final Transformer State                               Top Next-Character Candidates
    ( O ) In 0: [{h0:>7.3f}] ───\\
                                 \\
    ( O ) In 1: [{h1:>7.3f}] ─────X─────────────────> ( O ) Candidate '{c0}': {p0*100:>5.1f}% (Logit: {l0:>6.2f}){w0}
                                 / \\
    ( O ) In 2: [{h2:>7.3f}] ──/   \\───────────────> ( O ) Candidate '{c1}': {p1*100:>5.1f}% (Logit: {l1:>6.2f}){w1}
                                     \\
    ( O ) In 3: [{h3:>7.3f}] ─────────\\─────────────> ( O ) Candidate '{c2}': {p2*100:>5.1f}% (Logit: {l2:>6.2f}){w2}
                                       \\
                                        ────────────> ( O ) Candidate '{c3}': {p3*100:>5.1f}% (Logit: {l3:>6.2f}){w3}
  ===========================================================================================""")


# =====================================================================
# 5. FORWARD PASS EXECUTION
# =====================================================================
def transformer_step(token_ids, context_chars):
    T = len(token_ids)
    last_char = context_chars[-1]
    last_pos = T - 1

    # Step 1: Embeddings
    X = []
    for pos, tok_id in enumerate(token_ids):
        tok_vec = token_embedding_table[tok_id]
        pos_vec = position_embedding_table[pos]
        combined = [tok_vec[k] + pos_vec[k] for k in range(d_model)]
        X.append(combined)

    draw_embedding_stage(
        last_char,
        token_ids[-1],
        last_pos,
        token_embedding_table[token_ids[-1]],
        position_embedding_table[last_pos],
        X[-1],
    )

    # Step 2: Causal Attention Pre-LN & Projections
    X_norm1 = layer_norm(X)
    Q = matrix_mul(X_norm1, W_q)
    K = matrix_mul(X_norm1, W_k)
    V = matrix_mul(X_norm1, W_v)

    draw_qkv_stage(X_norm1[-1], Q[-1], K[-1], V[-1])

    # Step 3: Attention Scores & Causal Mask
    scores = matrix_mul(Q, transpose(K))
    scale = 1.0 / math.sqrt(d_model)
    for i in range(T):
        for j in range(T):
            scores[i][j] *= scale
            if j > i:
                scores[i][j] = -1e9

    attn_weights = [softmax(row) for row in scores]
    context = matrix_mul(attn_weights, V)
    attn_out = matrix_mul(context, W_proj)
    X_res1 = add_matrices(X, attn_out)

    draw_attention_weights_stage(context_chars, last_char, attn_weights[-1])

    # Step 4: Feed-Forward Network (MLP)
    X_norm2 = layer_norm(X_res1)
    hidden_ffn = matrix_mul(X_norm2, W_mlp1)
    relu_ffn = [[max(0.0, val) for val in row] for row in hidden_ffn]
    ffn_out = matrix_mul(relu_ffn, W_mlp2)
    X_res2 = add_matrices(X_res1, ffn_out)

    draw_feed_forward_stage(X_norm2[-1], relu_ffn[-1], ffn_out[-1])

    # Step 5: Output Projection & Softmax
    X_final = layer_norm(X_res2)
    logits = matrix_mul(X_final, W_lm_head)
    last_logits = logits[-1]
    last_probs = softmax(last_logits)

    return last_logits, last_probs, X_final[-1]


# =====================================================================
# 6. INTERACTIVE CONSOLE RUNNER
# =====================================================================
def run_interactive_pipeline():
    print("=" * 91)
    print(" 🚀 ARBITRARY STRING AUTOREGRESSIVE TRANSFORMER VISUALIZER")
    print("=" * 91)
    print(f"Known Vocabulary Universe ({vocab_size} classes): {''.join(vocabulary[1:])}")
    print("Any unlisted character will automatically map to '<unk>' without crashing.")
    print("-" * 91)

    raw_input_str = input("Enter any word or prompt string: ").strip()
    if not raw_input_str:
        raw_input_str = "Hi"

    cycles_input = input("Enter number of tokens to generate (e.g. 2 or 3): ").strip()
    max_cycles = int(cycles_input) if cycles_input.isdigit() and int(cycles_input) > 0 else 2

    current_sequence = raw_input_str

    for cycle in range(max_cycles):
        # Align tokens and characters strictly together
        raw_chars = list(current_sequence)
        token_ids = encode(raw_chars)

        # Enforce context window sliding
        if len(token_ids) > block_size:
            token_ids = token_ids[-block_size:]
            raw_chars = raw_chars[-block_size:]

        print(f"\n{'#' * 91}")
        print(f" 👉 AUTOREGRESSIVE GENERATION CYCLE {cycle + 1} | CURRENT PROMPT: \"{current_sequence}\"")
        print(f"{'#' * 91}")

        last_logits, last_probs, final_h = transformer_step(token_ids, raw_chars)

        # Get top 4 candidate choices
        candidates = []
        for idx, (logit, prob) in enumerate(zip(last_logits, last_probs)):
            label = idx2char[idx] if idx2char[idx] != "<unk>" else "?"
            candidates.append((label, logit, prob))
        candidates.sort(key=lambda x: x[2], reverse=True)
        top_4 = candidates[:4]

        # Greedy selection (ArgMax)
        chosen_char = top_4[0][0]

        draw_final_output_gate(final_h, top_4, chosen_char)

        current_sequence += chosen_char
        print(f"\n[Cycle {cycle + 1} Result] Produced Next Token: '{chosen_char}' -> Sequence is now: \"{current_sequence}\"")
        time.sleep(0.3)


if __name__ == "__main__":
    run_interactive_pipeline()