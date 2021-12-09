class Base1:
    def __init__(self):
        self.__base1 = 'Base1'

    def Print(self):
        print(self.__base1)


class Base2:
    def __init__(self):
        self.__base2 = 'Base2'

    def Print(self):
        print(self.__base2)


class Derived(Base1, Base2):
    def __init__(self):
        Base1.__init__(self)
        Base2.__init__(self)
        self.__derived = 'Derived'

    def Print(self):
        Base1.Print(self)
        Base2.Print(self)
        print(self.__derived)


if __name__ == "__main__":
    d = Derived()

    # => Base1
    # => Base2
    # => Derived
    d.Print()
