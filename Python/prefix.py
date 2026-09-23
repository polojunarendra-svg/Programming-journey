#How it is calculated:Index 0: 3 Index 1: 3 + 1 = 4 Index 2: 3 + 1 + 5 = 9Index 3: 3 + 1 + 5 + 2 = 11
lst=[3, 1, 5, 2]
for i in range(1,len(lst)):
    lst[i]=lst[i]+lst[i - 1]
print(lst)
