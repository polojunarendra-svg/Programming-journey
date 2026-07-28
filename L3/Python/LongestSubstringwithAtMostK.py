# Example: s = "eceba", k = 2 -> 3("ece")
# word = "abracadabra"
# freq = {ch: word.count(ch) for ch in set(word)}
# print(f"Letter frequencies: {freq}")
string="eceba"
k=2
freq={ch:string.count(ch) for ch in set(string)}
for ch in freq:
    if freq[ch]==k:
        print(ch,freq[ch])
