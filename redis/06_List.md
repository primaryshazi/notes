# List

## 头部追加值

    LPUSH Key Value_1 Value_2

## 头部删除值

    LPOP Key

## 仅在列表存在时头部追加

    LPUSHX Key Value_1 Value_2

## 删除尾部值

    RPOP Key

## 尾部追加值

    RPUSH Key Value_1 Value_2

## 仅在列表存在时尾部追加

    RPUSHX Key Value_1 Value_2

## 删除列头尾部值，无值则阻塞至有值或达到超时时间

    BLPOP Key_1 Key_2 Timeout

## 删除列表尾部值，无值则阻塞至有值或达到超时时间

    BRPOP Key_1 Key_2 Timeout

## 移动列表最后一个值至其他列表

    RPOPLPUSH Source Destination

## 移动列表最后一个值至其他列表，无值则阻塞至有值或达到超时时间

    BRPOPLPUSH Source Destination Timeout

## 插入列表值

    # 在第一个ExistsValue之前插入Value
    LINSERT Key BEFORE ExistsValue Value

    # 在第一个ExistsValue之后插入Value
    LINSERT Key AFTER ExistsValue Value

## 获取指定索引处的值

    LINDEX Key Index

## 获取列表长度

    LLEN Key

## 获取指定范围内的值

    LRANGE Key Start Stop

## 设置列表指定索引处值

    LSET Key Index Value

## 移除列表元素

    # 删除指定个数的指定值
    LREM Key Count Value

## 修建列表保留剩余部分

    LTRIM Key Start Stop
