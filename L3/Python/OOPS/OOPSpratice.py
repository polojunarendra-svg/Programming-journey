class Demo:
    def enginestarted(self):
        print("Engine has started'")
class v1(Demo):
    def stared(self):
        print(" v1 is started ")
class v2(Demo):
    def stared(self):
        print(" v2 is started ")
v11 = v1()
v11.enginestarted()
v22 = v2()
v22.enginestarted()
# class demo:
#     def enginestarted(self):
#         print("Engine has started'")
# class v1:
#     d = demo()
#     d.enginestarted()
#     def enginestarted(self):
#         print("v1 Engine has started'")
#     v=v1()
#     v.enginestarted()
# class v2:
#     d = demo()
#     d.enginestarted()
#     def enginestarted(self):
#         print("v2 Engine has started'")
#     v=v2()
#     v.enginestarted()