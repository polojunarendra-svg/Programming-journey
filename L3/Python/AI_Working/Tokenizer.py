# data = "Hello world! i  am learning to build an ai model from the stratch."
# vocabulary = sorted(list(set(data)))
# print(data,"\n",vocabulary,"\n",len(vocabulary))
# stringtointeger={}
# integertostring={}
# for idx , char in enumerate(vocabulary):
#     stringtointeger[char] = idx
#     integertostring[idx] = char
# print(stringtointeger,"\n",integertostring,"\n",len(integertostring))
# def encode(text):
#     ans = []
#     for ch in text:
#         if ch in stringtointeger:
#             ans.append(stringtointeger[ch])
#         else:
#             print(f"Warning:'{ch}' is not in our vocabulary dictionary!")
#     return ans
# encoded_result=encode("Hi")
# print("Encoded Integer IDs:",encoded_result)
# def decode(text):
#     ans = []
#     for i in text:
#         if i in integertostring:
#             ans.append(integertostring[i])
#         else:
#             print(f"Warning:'{i}' is not in our vocabulary dictionary!")
#     return "".join(ans)
# encoded_result=decode(encoded_result)
# print("Decoded Integer IDs:",encoded_result)
# =====================================================================
# 🚀 Coding the Codebasics Embedding Tutorial from Scratch
# =====================================================================
import random

random.seed(42)

# Global configuration from your tokenizer step
vocab_size = 22
input_tokens = [3, 12]  # Integer IDs for "Hi"


# ---------------------------------------------------------------------
# 1) TECHNIQUE 1: Unique Numbers Representation
# ---------------------------------------------------------------------
def get_unique_numbers(tokens):
    # Simply returns the token list itself as the baseline
    return tokens


# ---------------------------------------------------------------------
# 2) TECHNIQUE 2: One-Hot Encoding
# ---------------------------------------------------------------------
def get_one_hot_encoded(tokens, size_of_vocab):
    one_hot_matrix = []

    for token_id in tokens:
        # Create a blank vector of zeros matching your vocabulary size (22)
        zero_vector = [0] * size_of_vocab

        # Flip the item at the exact token_id position to a 1
        zero_vector[token_id] = 1
        one_hot_matrix.append(zero_vector)

    return one_hot_matrix


# ---------------------------------------------------------------------
# 3) TECHNIQUE 3: Word Embeddings (Dense Feature Vectors)
# ---------------------------------------------------------------------
# Setup a 22x4 random embedding lookup matrix (representing hidden machine-learned features)
embedding_matrix = []
embedding_dim = 4

for i in range(vocab_size):
    row = []
    for j in range(embedding_dim):
        row.append(round(random.uniform(-1.0, 1.0), 4))
    embedding_matrix.append(row)


def get_word_embeddings(tokens):
    embedded_vectors = []
    for token_id in tokens:
        # Pull out the dense continuous float feature vector row
        embedded_vectors.append(embedding_matrix[token_id])
    return embedded_vectors


# =====================================================================
# 🧪 Executing and Visualizing the Differences
# =====================================================================

print("=== INPUT TEXT COMPONENT: 'Hi' ===")

# Technique 1 Output
unique_out = get_unique_numbers(input_tokens)
print(f"\n1) Unique Numbers Output:\n   {unique_out}")

# Technique 2 Output
one_hot_out = get_one_hot_encoded(input_tokens, vocab_size)
print(f"\n2) One-Hot Encoded Vector Matrix (Shape: {len(one_hot_out)}x{len(one_hot_out[0])}):")
for vector in one_hot_out:
    print(f"   {vector}")

# Technique 3 Output
embeddings_out = get_word_embeddings(input_tokens)
print(f"\n3) Dense Word Embeddings Matrix (Shape: {len(embeddings_out)}x{len(embeddings_out[0])}):")
for vector in embeddings_out:
    print(f"   {vector}")
