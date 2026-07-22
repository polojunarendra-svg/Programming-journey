class cls:
    # def __init__(self):
    #     print("Constructor")
    def __init__(self,a):
        self.a=a
    def foo(self):
        print(self.a)
c = cls(15)
c.foo()