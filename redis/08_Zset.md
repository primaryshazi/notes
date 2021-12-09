# Zset

## 添加成员

    # Member -> Score
    ZADD Key Score_1 Member_1 Score_2 Member_2

## 删除成员

    ZREM Key Member_1 Member_2

## 删除范围内的成员

    # 索引
    ZREMRANGEBYRANK Key Start Stop

    # 全部
    ZREMRANGEBYLEX key - +

    # 指定范围
    ZREMRANGEBYLEX Key [Member_Min [Member_Max

## 获取指定范围内的成员

    # 从小至大索引
    ZRANGE Key Start Stop

    # 从大至小
    ZREVRANGEBYSCORE Key Score_Max Score_Min

    # 全部
    ZRANGEBYLEX key - +

    # 指定范围
    ZRANGEBYLEX Key [Member_Min [Member_Max

## 获取指定返回值

    ZRANGEBYSCORE Key Score_Min Score_Max

## 获取成员下标

    # 从小至大
    ZRANK key Member

    # 从大至小
    ZREVRRANK Key Member

## 获取成员数量

    ZCARD Key

## 获取区间成员数量

    ZCOUNT Key Score_Min Score_Max

    # 全部
    ZLEXCOUNT key - +

    # 指定范围
    ZLEXCOUNT Key [Member_Min [Member_Max

## 获取指定成员值

    ZSCORE Key Member

## 指定成员增加值

    ZINCRBY Key Increment Member

## 集合交集储存

    # 指定集合的数量为Num_key
    ZINTERSTORE Destination Num_key Key_1 Key_2

## 集合并集储存

    # 指定集合的数量为Num_key
    ZUNIONSTORE Destination Num_key Key_1 key_2

## 迭代有序集合

    ZSCAN Key Cursor MATCH * COUNT Count
