# n = 6
# i=1
# m=n+1
# for i in range(m):
#     a = n-i
#     print(" "*a+i*"#")
#======================================
#MInMax of an array
def miniMaxSum(arr):
    # arr.sort()
    # # Write your code here
    # sum=0
    # rsum=0
    # n=len(arr)
    # for i in range(0,n-1):
    #     sum+=arr[i]
    # for i in range(1,n):
    #     rsum+=arr[i]
    # return [sum,rsum]
    #======================
    total = sum(arr)
    maximum = total-min(arr)
    minimum = total-max(arr)
    return minimum,maximum
arr = [7 ,69, 2 ,221 ,8974]
ans = miniMaxSum(arr)
print(ans)