class Test:
    def __init__(self):
        self.value = 0  # 公有变量
        self._value = 1
        self.__value = 2  # 私有变量

    def Print(self):  # 公有函数
        self.__Print()

    def _Print(self):
        self.__Print()

    def __Print(self):  # 私有函数
        print(self.value, self._value, self.__value)


if __name__ == "__main__":
    t = Test()

    # => 0 1 2
    # => 0 1 2
    # => 0
    # => 1
    t.Print()
    t._Print()
    # t.__Print()     # 不可访问
    print(t.value)
    print(t._value)
    # print(t.__value)    # 不可访问
