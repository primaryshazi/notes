# String

## 设置键值

    SET Key Value

## 获取键值

    GET Key

## 获取子串

    GETRANGE Key Start End

## 获取旧值并设置新值

    GETSET Key Value

## 设置字符串偏移量上的位

    SETBIT Key Offset Value

## 获取字符串偏移量上的位

    GETBIT Key Offset

## 设置多个键值

    MSET Key_1 Value_1 Key_2 Value_2

## 获取多个键值

    MGET Key_1 Kye_2

## 关联值到键并设置超时时间

    # 设置秒数级
    SETEX Key Second Value

    # 设置毫秒级
    PSETNX Key Millisecond Value

## 键不存在时设置键值

    SETNX Key Value

## 键不存在时设置多个键值

    MSETNX Key_1 Value_1 Key_2 Value_2

## 从指定偏移量开始覆盖字符串

    SETRANGE Key Offset Value

## 返回字符串的长度

    STRLEN Key

## 将数字字符串自增1

    INCR Key

## 将数字字符串增加指定值

    INCRBY Key Increment

## 将数字字符串增加浮点值

    INCRBYFLOAT Key Increment

## 将数字字符串自减1

    DECR Key

## 将数字字符串减少指定值

    DECRBY Key Decrement

## 追加字符串

    APPEND Key Value
