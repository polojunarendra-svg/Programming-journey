def Split(text):
    list = []
    word=""
    for i in text:
        if i!=' ':
            word = word+i;
        list.append(word)
        word=" "
    return list
def length(str):
    count=0;
    while str[i]!='\0':
        count=count+1;
    return count
words= "Bob hit a ball Bob hit a ball Bob hit a ball"
Words = Split(words)
print(Words)

