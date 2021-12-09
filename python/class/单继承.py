class Base:  # 私有成员对子类不可见
    def __init__(self):
        self.__base = 'Base'

    def Print(self):
        print(self.__base)


class Derived(Base):
    def __init__(self):
        super().__init__()  # 调用基类的构造函数
        self.__derived = 'Derived'

    def Print(self):  # 覆盖父类方法
        super().Print()
        print(self.__derived)


if __name__ == "__main__":
    b = Base()
    d = Derived()

    # => Base
    b.Print()

    # => Base
    # => Derived
    d.Print()
