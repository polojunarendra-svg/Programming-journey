# Praticing the oeration with 1 dimensional list
#=========================================================================
# v1 = [2,3,4,5,6]
# v2 = [4,6,8,1,3]
# mul=[]
# add=[]
# print("Vector 1 is",v1)
# print("Vector 2 is",v2)
# n = len(v1)
# m = len(v2)
# if n==m:
#     for i in range(n):
#         mul.append(v1[i] * v2[i])
# print("The product of vector1 and vector 2 is ",mul)
# if n==m:
#     for i in range(n):
#         add.append(v1[i] +v2[i])
# print("The sum of vector1 and vector 2 is ",add)
#=========================================================================
# In this only addition of the 2 dimensional list is valid but the matrix multiplication
# not done in that way so in the given below there will be a method for matrix multiplication
#
# v1 = [[1,2,3],[4,5,6],[7,8,9]]
# v2=[[9,8,7],[6,5,4],[3,2,1]]
# add=[]
# mul=[]
# n= len(v1)
# n1=len(v1[0])
# m1 = len(v2[0])
# m= len(v2)
# if n==m & n1==m1:
#     for i in range(n):
#         row_list=[]
#         for j in range(n1):
#             res=v1[i][j]+v2[i][j]
#             row_list.append(res)
#         add.append(row_list)
# print("Addition of the 2 dimensionallists are :",add)
# if n==m & n1==m1:
#     for i in range(n):
#         row_list=[]
#         for j in range(n1):
#             res=v1[i][j]*v2[i][j]
#             row_list.append(res)
#         mul.append(row_list)
# print("The multiplication of the 2 matrix is :",mul)
#
# # print(n)
# # print(m)
# # print(n1)
# # print(m1)
# Method for matix multiplication of the 2 d array or the list
#===========================================================================================================
# def matrix_mul(m1, m2_matrix):  # Renamed input to avoid overwriting conflicts
#     mul = []
#     n = len(m1)
#     n1 = len(m1[0])
#     m = len(m2_matrix)
#     cols_m2 = len(m2_matrix[0])
#
#     if n1 != m:
#         print("Error: The columns of the first matrix and the rows of the second matrix are not equal.")
#         return None
#
#     if n1 == m:
#         for i in range(n):
#             mul.append([0] * cols_m2)
#         for i in range(n):
#             for j in range(cols_m2):
#                 dot_product_sum=0
#                 for k in range(n1):
#                     dot_product_sum+=m1[i][k]*m2_matrix[k][j]
#                 mul[i][j]=dot_product_sum
#     return mul
#
#
#
# v1 = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
# v2 = [[9, 8, 7], [6, 5, 4], [3, 2, 1]]
#
# result = matrix_mul(v1, v2)
# print("The multiplication result is:")
# print(result)
#==========================================================================================================


