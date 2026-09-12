class base:
    """A base class for a circle."""
    def __init__(self):
        self.__radius = 10
    def speak(self):
        print(self.__radius)

baseobj = base()
print(baseobj.__radius)
baseobj.speak()
