paragraph = """Hi, Nice to meet you. What about your hobbies? """
word=""
none = None
words=[]
# for letter in paragraph:
#     if letter in ['.',',',' ']:
#         words.append(word)
#         word=""
#         # print()
#     else:
#         word=word+letter
for letter in paragraph:
    if letter in ['.',',',' ']:
        if word!="":
            words.append(word)
        word=""
        # print()
    else:
        word=word+letter

print(words)
def split(paragraph,listofsuperators):
    word=""
    words=[]
    for letter in paragraph:
        if letter in listofsuperators:
            words.append(word)
            word=""
            print()
        else:
            word = word+letter
        return words