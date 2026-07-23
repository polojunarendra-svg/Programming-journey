number=input("Enter the Number: ")
n=len(number)
left=0
right=n-1
count=0
while left<right:
    if number[left]==number[right]:
        count+=1
    left+=1
    right-=1
if count==n//2:
    print("Entered Number is Palindrome")
else:
    print("Entered number is not a palindrome")