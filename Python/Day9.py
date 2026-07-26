"""
public class Cls{
int a;
public Cls(int a){
this.a = a;
}

public void foo(){
System.out.println(a);
}
public static void main(String[]args){

Cls c = new Cls(15);
c.foo();

}
}
"""


class noclass:
    pass


class minclass:
    def __init__(self):
        pass


class MyClass:
    def __init__(self, a):
        self.a = a

    def foo(self):
        print(self.a)


object = MyClass(15)
object.foo()

def functions():
    pass

def functions2(a):
    print(a)


functions2(154)

def function3(a=15, b=56, c=89):
    print(a, b, c)


function3(89)
function3(89, 99, 56)


def function4(a, b, c=89):
    print(a, b, c)


def function5(a, b, c=89):
    print(a, b, c)


function5(45, 56, 78)


def add(a, b, c=56):
    return a + b + c


# def add(a,b):
#     return a + b

# print("hi",add(5,6))

print(add(4, 4, 5))


def add(a, b, c, *remaining):
    # print(type(remaining))
    # return sum(a+b+c+remaining)
    print(sum(remaining))
    return a + b + c + sum(remaining)


print(add(4, 5, 6, 7, 8, 7, 8, 7, 9, 5, 4))


def add(**hio):
    print(hio)



add(a=4, b=6, c=6)