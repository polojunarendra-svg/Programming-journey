# Example: s = "eceba", k = 2 -> 3("ece")
# word = "abracadabra"
# freq = {ch: word.count(ch) for ch in set(word)}
# print(f"Letter frequencies: {freq}")
string = "acgacvs"
k = 2
ans = ""
for i in range(len(string)):
    current=""
    for j in range(i,len(string)):
        if string[j] not in current:
            if len(set(current))==k:
                break
        current=current+string[j]
        if len(current)>len(ans):
            ans=current

print(ans)
