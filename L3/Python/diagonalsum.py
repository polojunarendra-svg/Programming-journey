def diagonalDifference(arr):
    # Write your code here
    n = len(arr)
    sum=0
    rsum=0
    # We can also do this in the single for loop
    for i in range(n):
        sum+=arr[i][i]
    for j in range(n):
            rsum+=arr[j][n-1-j]
    if sum>rsum:
        return sum-rsum
    else:
        return rsum-sum
arr =[[1, 2, 3], [4, 5, 6], [7, 8, 9]]
result = diagonalDifference(arr)
print(result)