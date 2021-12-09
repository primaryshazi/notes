# Set

## 添加值

    SADD Key Value_1 Value_2

## 删除值

    SREM Key Value_1 Value_2

## 随机移除一个值

    SPOP Key

## 随机返回值

    # 随机返回Count个值，默认为1
    SRANDMEMBER Key Count

## 获取值数量

    SCARD Key

## 获取集合所有值

    SMEMBERS Key

## 值是否存在

    SISMEMBER Key Value

## 集合交集

    SINTER Key_1 Key_2

## 集合交集储存

    SINTERSTORE Destination Key_1 Key_2

## 集合与其他集合差集

    SDIFF Key_1 Key_2

## 集合与其他集合差集储存

    SDIFFSTORE Destination Key_1 Key_2

## 集合并集

    SUNION Key_1 Key_2

## 集合并集储存

    SUNION Destination Key_1 Key_2

## 移动集合中的值

    SMOVE Source Destination Value

## 迭代集合

    SSCAN Key Cursor MATCH Match COUNT Count
