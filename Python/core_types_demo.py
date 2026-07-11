a=10
print(id(a))#140713070396616
print(type(a))
print(a)
b=a
print(a==b)
print(id(b))
a=a+1
print(id(a),a)
print(id(b),b)
print(a==b)
a=10
print(a is b)
a=[1,2]
b=a
a.append(3)
print(a)
print(b)
# list = [1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]
# list.append(2)
# list.insert(5,6456)
# list.pop(1)
# list.remove(2)
# list.extend([2])
# list.clear()
# print(list)
text = "Na r e nd r a"
result = text.count('N')
print(result)
name= text.replace(" ", "")
print(name)
name =name.casefold()
print(name)
d = [1,2,3,4,5,6,7,8,9,10]
square = [i*i for i in d]
print(square)

word = "abracadabra"
freq = {ch: word.count(ch) for ch in set(word)}
print(f"Letter frequencies: {freq}")

