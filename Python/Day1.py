paragraph = "Bold hit an bat"
j=0
word=""
temp =""
i=0
start=0
while(j<len(paragraph)):
    if(paragraph[j]==" "):
        print("\n")
        j+=1
        continue
    print(paragraph[j],end="")
    j+=1
