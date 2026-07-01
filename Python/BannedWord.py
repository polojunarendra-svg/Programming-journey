def Split(text):
    list = []
    word=""
    for i in text:
        if i!=" ":
            word = word+i;
        else:
           if word!=" ":
               list.append(word)
           word=" "
    if word != " ":
            list.append(word)
    return list

def length(str):
    count=0;
    while str[i]!='\0':
        count=count+1;
    return count
words= "Bob hit a ball Bob hit a ball Bob hit a ball Bob hit a ball Bob hit a ball Bob hit a ball"
Words = Split(words)
print(Words)
uniquewords=[]
uniquewordsfrequency=[]
# uniquewords=set(Words)
# {' Bob', ' a', ' hit', 'Bob', ' ball'}
for i in Words:
    if i.rstrip() not in uniquewords:
        uniquewords.append(i)

print(uniquewords)
for i in uniquewords:
    count=0
    for j in Words:
        if i==j:
            count=count+1;
    uniquewordsfrequency.append(count)
print(uniquewordsfrequency)
max=0
for i in range(len(uniquewordsfrequency)):
    for j in range(len(uniquewordsfrequency)):
        if uniquewordsfrequency[i]>uniquewordsfrequency[j]:
            temp = uniquewordsfrequency[i]
            uniquewordsfrequency[i]=uniquewordsfrequency[j]
            uniquewordsfrequency[j]=temp
            tempo=uniquewords[i]
            uniquewords[i]=uniquewords[j]
            uniquewords[j]=tempo
            max=max+1
print(uniquewords)
print(uniquewordsfrequency)
bannedword = "Bob"
if uniquewords[0].strip()==bannedword:
    print(uniquewords[1],uniquewordsfrequency[1])
else:
    print(uniquewordsfrequency[0],uniquewords[0])
# # dict = {}
# for i in range(len(uniquewordsfrequency)):
#     dict[uniquewords[i].rstrip()]=uniquewordsfrequency[i]
# print(dict)
# for i in dict.items():
#     for j in dict.values():
#         if(dict[i]>dict[j]):
#             temp = dict[i]
#             dict[i]=dict[j]
#             dict[j]=temp
#             tempw =