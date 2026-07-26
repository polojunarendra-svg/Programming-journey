list =[3,1,5,2]
ans=list
print(ans)
n = len(list)
for i in range(n):
    j=i+1
    if j<=n:
        list[i]=ans[i]+ans[j]
print(ans)