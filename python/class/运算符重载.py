# __init__      构造函数
# __del__       析构函数
# __repr__      打印，转换
# __setitem__   按照索引赋值
# __getitem__   按照索引获取值
# __len__       获得长度
# __cmp__       比较运算
# __call__      函数调用
# __add__       加运算
# __sub__       减运算
# __mul__       乘运算
# __truediv__   除运算
# __mod__       求余运算
# __pow__       乘方
# __lt__        小于
# __le__        小于等于
# __gt__        大于
# __ge__        大于等于
# __eq__        等于
# __ne__        不等于


class Test:
    def __init__(self, id: int):
        self.__id = id
        print(str('{:s} : {:s}').format(self.__class__.__name__, 'construct'))

    def __del__(self):
        print(str('{:s} : {:s}').format(self.__class__.__name__, 'destruct'))

    def __gt__(self, other):
        return self.__id > other.__id

    def __lt__(self, other):
        return self.__id < other.__id

    def __eq__(self, other):
        return self.__id == other.__id

    def __str__(self):
        return str('{:s} : {:d}').format(self.__class__.__name__, self.__id)


if __name__ == "__main__":
    # => Test : construct
    # => Test : construct
    t1 = Test(1)
    t2 = Test(2)

    # => Test : 1
    # => Test : 2
    print(t1)
    print(t2)

    # => False
    # => True
    # => False
    print(t1 > t2)
    print(t1 < t2)
    print(t1 == t2)

    # => Test : destruct
    # => Test : destruct
