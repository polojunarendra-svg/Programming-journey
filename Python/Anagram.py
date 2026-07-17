List = ["eat","tea","tan","ate","nat","bat"]
def Sorted(text):
    text = list(text)
    word = ""
    for i in range(len(text)):
        for j in range(i,len(text)):
            if(text[i]>text[j]):
                temp=text[i]
                text[i]=text[j]
                text[j]=temp
    return Adding(text)
def length(text):
    count=0
    for i in text:
        count=count+1
    return count
def Adding(text):
    ans = ""
    for i in text:
        ans = ans+i
    return ans
RealList=[]
for lst in List:
    RealList.append(Sorted(lst))
for i in RealList:
    print(i)
ans =[]
temp=[]
uniquecheck=[]
for i in range(len(RealList)):
    if i in uniquecheck:
        continue
    for j in range(length(RealList)):
        if(RealList[i]==RealList[j]):
            temp.append(List[j])
            uniquecheck.append(j)
    ans.append(temp)
    temp=[]
#print(ans)
for i in ans:
    print(i)