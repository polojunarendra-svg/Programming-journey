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
print(mul(-8,13))
# def add(a,b):
#
#     return a^b
# def sub(a,b):
#     return a+~b+1
# # print(sub(8,3))
# # print(add(3,7))
# # print(bin(54))
# class Demo:
#     def ___init__(self):
#         print("Hello")
#     def __init__(self,a):
#         self.a=a
#     def print(self):
#         print(self.a)
# # d=Demo(12)
# # d.print()
# # def print(text):
# #     n=int(input(":"))
# #     for i in range(n):
# #         print(i," ",text)
# # # print("Hello")
# # def none(a):
# #     print(a)
# # none(3)
# # def function4(a, b, c=89):
# #     print(a, b, c)
# # function4("Hi",3)
# def function5(a, b,*c):
#     return a,b,*c
# print(function5(1,2,3,4,5,6,7,8,9,10,12,23,35))