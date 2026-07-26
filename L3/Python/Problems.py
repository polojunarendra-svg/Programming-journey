def length(arr):
    count = 0
    for _ in arr:
        count += 1
    return count

def TwoSum(arr,target):
    n = length(arr)
    left=0
    right=n-1
    arr.sort()
    while(left<right):
        if(arr[left]+arr[right]==target):
            return [left,right]
        elif arr[left]+arr[right]<target:
            left=left+1
        else:
            right=right-1
    if ans!=-1:
        return ans
    else:
        return -1
# arr=[2,7,11]
# target=9
# ans=TwoSum(arr,target)
# print(ans)
def ProductOfArray(arr):
    n = length(arr)
    left=0
    product=1
    count=0
    i=0
    ans=[n]
    while left<n:
        if i == left:
            i=i+1
            continue
        product=product*arr[i]
        i=i+1
        count=count+1;
        if count==n-1:
            print(product,end=" ")
            ans.append(product)
            left=left+1
            count=0
            i=0
            product=1

    return ans
# arr=[1,2,3,4]
# ProductOfArray(arr)
def subArraySum(arr,target):
    n = length(arr)
    left=0
    i=0
    count=0
    right=left+1
    sum=0
    while(left<n-1):
        sum=sum+arr[i]
        if(sum==target):
            left=left+1
            count=count+1
            sum=0
        else:
            right=right+1
            i=i+1

    print(count)
arr= [1,1,1]
k=2
subArraySum(arr,k)
def longestSubString(str1):
    n = length(str1)
    ls = list(str1)
    un = set(ls)
    ans = ""
    for i in un:
        ans=ans+i
    if ans in str1:
        return ans

    # print(ls)
    # print(un)
    # print(ans)
# print(longestSubString("abcabcbb"))
