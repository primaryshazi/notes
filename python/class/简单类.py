class Test1:
    def Print(self, message: str):
        print(str.format('{:s} : {:s}', self.__class__.__name__, message))


class Test2:
    def __init__(self):  # 初始化函数
        self.m_name = self.__class__.__name__  # 类名

    def Print(self, message: str):
        print(str.format("{:s} : {:s}", self.m_name, message))


class Test3:
    def __init__(self, name: str = 'Test3'):
        self.m_name = name

    def Print(self, message: str):
        print(str.format("{:s} : {:s}", self.m_name, message))


if __name__ == "__main__":
    t1 = Test1()
    t2 = Test2()
    t3 = Test3()
    t4 = Test3('Test4')

    # => Test1 : Hello World!
    # => Test2 : Hello World!
    # => Test3 : Hello World!
    # => Test4 : Hello World!
    t1.Print('Hello World!')
    t2.Print('Hello World!')
    t3.Print('Hello World!')
    t4.Print('Hello World!')
