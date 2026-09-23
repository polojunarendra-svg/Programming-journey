import math
import random

random.seed(42)

# =====================================================================
# 🎫 PHASE 1: TOKENIZER WITH EXPLICIT <unk> FALLBACK
# =====================================================================
training_data = "Hello world! i  am learning to build an ai model from the stratch."
# Reserve index 0 for Unknown characters (<unk>)
base_vocab = sorted(list(set(training_data)))
vocabulary = ["<unk>"] + base_vocab
vocab_size = len(vocabulary)

stringtointeger = {ch: idx for idx, ch in enumerate(vocabulary)}
integertostring = {idx: ch for idx, ch in enumerate(vocabulary)}


def encode(text):
    ids = []
    tokens = []
    for ch in text:
        if ch in stringtointeger:
            ids.append(stringtointeger[ch])
            tokens.append(ch)
        else:
            print(f"[Warning] Character '{ch}' mapped to <unk> (ID: 0)")
            ids.append(stringtointeger["<unk>"])
            tokens.append("<unk>")
    return tokens, ids


# =====================================================================
# 🔲 PHASE 2: DENSE EMBEDDINGS (vocab_size x 4)
# =====================================================================
embedding_dim = 4
embedding_matrix = [
    [round(random.uniform(-1.0, 1.0), 4) for _ in range(embedding_dim)]
    for _ in range(vocab_size)
]


def get_embeddings(token_ids):
    return [embedding_matrix[tid] for tid in token_ids]


# =====================================================================
# 🧠 PHASE 3: LINEAR, RELU, SOFTMAX, ARGMAX
# =====================================================================
in_features = 4
out_features = 3  # 3 target projection classes

weights = [
    [round(random.uniform(-1.0, 1.0), 4) for _ in range(out_features)]
    for _ in range(in_features)
]
bias = [round(random.uniform(-0.1, 0.1), 4) for _ in range(out_features)]


def matrix_mul(m1, m2):
    r1, c1 = len(m1), len(m1[0])
    r2, c2 = len(m2), len(m2[0])
    mul = [[0.0] * c2 for _ in range(r1)]
    for i in range(r1):
        for j in range(c2):
            mul[i][j] = sum(m1[i][k] * m2[k][j] for k in range(c1))
    return mul


def linear_forward(X, W, b):
    multiplied = matrix_mul(X, W)
    for i in range(len(multiplied)):
        for j in range(len(multiplied[0])):
            multiplied[i][j] = round(multiplied[i][j] + b[j], 4)
    return multiplied


def relu(matrix):
    return [[max(0.0, val) for val in row] for row in matrix]


def softmax(matrix):
    out = []
    for row in matrix:
        max_val = max(row)
        exp_row = [math.exp(x - max_val) for x in row]
        sum_exp = sum(exp_row)
        out.append([round(e / sum_exp, 4) for e in exp_row])
    return out


def argmax(prob_matrix):
    return [row.index(max(row)) for row in prob_matrix]


# =====================================================================
# 🖥️ PHASE 4: ASCII FORWARD PASS DIAGRAM
# =====================================================================
def draw_network(token_str, token_id, in_vec, logits, relu_out, probs, win_idx):
    in1, in2, in3, in4 = [round(x, 4) for x in in_vec]
    p0, p1, p2 = [round(x * 100, 1) for x in probs]

    w0 = " ★ Winner" if win_idx == 0 else ""
    w1 = " ★ Winner" if win_idx == 1 else ""
    w2 = " ★ Winner" if win_idx == 2 else ""

    print(f"""
========================================================================================
 🔍 CHAR: '{token_str}' (Token ID: {token_id}) | FORWARD PASS
========================================================================================
   INPUT LAYER (Dim = 4)                                 OUTPUT CLASSES (Softmax)

   ( O ) In 1: [{in1:>7}] ───\\
                             \\
   ( O ) In 2: [{in2:>7}] ─────X───────────────────> ( O ) Class 0: {p0:>5.1f}%  (Logit: {relu_out[0]:>6.3f}){w0}
                             / \\
   ( O ) In 3: [{in3:>7}] ──/   \\──────────────────> ( O ) Class 1: {p1:>5.1f}%  (Logit: {relu_out[1]:>6.3f}){w1}
                                 \\
   ( O ) In 4: [{in4:>7}] ────────\\────────────────> ( O ) Class 2: {p2:>5.1f}%  (Logit: {relu_out[2]:>6.3f}){w2}

  Pre-ReLU Logits:  {logits}
  Post-ReLU Gates:  {relu_out}
========================================================================================""")


# =====================================================================
# 🚀 EXECUTION PIPELINE
# =====================================================================
def run_pipeline(user_input):
    tokens, token_ids = encode(user_input)

    print(f"\n[Step 1] Tokens:    {tokens}")
    print(f"[Step 1] Token IDs: {token_ids}")

    embeddings = get_embeddings(token_ids)
    linear_out = linear_forward(embeddings, weights, bias)
    activated_out = relu(linear_out)
    probabilities = softmax(activated_out)
    winning_classes = argmax(probabilities)

    print("\n[Step 2] Processing Steps Table:")
    for i, t in enumerate(tokens):
        print(f"   '{t}' (ID {token_ids[i]}): Embed={embeddings[i]} -> ReLU={activated_out[i]} -> WinClass={winning_classes[i]}")

    print("\n" + "=" * 80)
    print(" 🖥️ CHARACTER-BY-CHARACTER ARCHITECTURAL DIAGRAMS")
    print("=" * 80)

    for i in range(len(tokens)):
        draw_network(
            token_str=tokens[i],
            token_id=token_ids[i],
            in_vec=embeddings[i],
            logits=linear_out[i],
            relu_out=activated_out[i],
            probs=probabilities[i],
            win_idx=winning_classes[i]
        )


if __name__ == "__main__":
    user_string = input("Enter a word or sentence: ").strip() or "Narendra"
    run_pipeline(user_string)