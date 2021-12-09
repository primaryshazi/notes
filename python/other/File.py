filename = 'temp.txt'

# r   只读，文件不存在报错
# w   只写，文件不存在创建
# a   追加，文件不存在追加
# x   只写，文件存在报错
# t   文本模式
# b   二进制模式
# +   读写
file = open(filename, 'a')
file.close()

# write()         只能写字符串
# writelines()    可以写字符串以及字符序列
# => 0
# => 1
# => 2
# => 3
# => 4
with open(filename, 'w') as file:
    if file.writable():
        for i in range(5):
            file.write(str.format('{:d}\n', i))
            print(i)

# read()      读取指定数量的字符
# readline()  读取一行，包括\n
# readlines() 读取所有，返回序列，包括\n
# => 0
# => 1
# => 2
# => 3
# => 4
with open(filename, 'r') as file:
    if file.readable():
        for line in file:
            print(line, end='')

# 截断文件
with open(filename, 'w') as file:
    if file.writable():
        file.truncate(0)

# seek() offset表示偏移量，whence表示起点(0：头，1：当前，2：尾)
# => 3
with open(filename, 'r') as file:
    if file.readable():
        file.seek(0, 2)
        print(file.tell())
