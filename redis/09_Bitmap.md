# Bitmap

## 指定Bit第N位为0或1

    SETBIT Bit N 0
    SETBIT Bit N 1

## 获取Bit第N位

    GETBIT Bit N

## 统计Bit[S, E]字节中位为1的个数

    BITCOUNT Bit
    BITCOUNT Bit S E

## 位操作

    BITOP AND Result Key_1 Key_2 ...
    BITOP OR Result Key_1 Key_2 ...
    BITOP XOR Result Key_1 Key_2 ...
    BITOP NOT Result Key_1 Key_2 ...

## 获取Bit[S, E]字节中位第一个为0/1的位置

    BITPOS Bit 0
    BITPOS Bit 1
    BITPOS Bit 1 S
    BITPOS Bit 1 S E
