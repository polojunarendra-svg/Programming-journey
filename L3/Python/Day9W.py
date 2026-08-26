# # n =int(input("Enter the n :"))
# # m =int(input("Enter the m :"))
# # print(bin(n)," ",bin(m))
# # print(bin(n<<m)," ",n<<m)
# def decimalToBinary(a):
#     s=""
#     while(a!=0):
#         n = a%2
#         s=s+str(n)
#         a//=2
#     return reversed(s)
# def reversed(str):
#     n=len(str)-1
#     rev=""
#     while(n>0):
#         rev+=str[n]
#         n=n-1
#     return rev
# def length(text):
#     i = 0
#     try:
#         while True:
#             text[i]
#             i += 1
#     except IndexError:
#         return i
#
# # ans = decimalToBinary(5)
# # print(ans)
# def Addition(a,b):
#     return a^b
def mul(a,b):
    i=0
    while b!=0:
        i=i+a
        a=a<<1
        b=b>>1
    return i
print(mul(8,3))
# print(bin(54))
