paragraph = "Bold Hit an hat"
j=0
words = []
temp=""
while(j<len(paragraph)):
    if(paragraph[j]==" "):
        words.append(temp)
        temp=""
        j+=1
        continue
    temp+=paragraph[j]
    #print(paragraph[j],end="")
    j+=1
words.append(temp)
print(words)