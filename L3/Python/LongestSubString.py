string="abcabcbb"
unq=""
for ch in string:
    if ch not in unq:
        unq=unq+ch
print(unq)