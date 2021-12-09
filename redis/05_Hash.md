# Hash

## 获取字段值

    HGET Key Field

## 设置字段值

    HSET Key Field Value

## 设置多个字段值

    HMSET Key Field_1 Value_1 Field_2 Value_2

## 获取多个字段值

    HMGET Key Field_1 Field_2

## 字段不存在时设置值

    HSETNX Key Field Value

## 删除多个字段

    HDEL Key Field_1 Field_2

## 指定字段是否存在

    HEXISTS Key Field

## 获取所有值

    HGETALL Key

## 数值字段值增加指定值

    HINCRBY Key Field Increment

## 数值字段值增加指定浮点值

    HINCRBYFLOAT Key Field Increment

## 获取所有的字段

    HKEYS Key

## 获取所有的值

    HVALS Key

## 获取表长度

    HLEN Key

## 迭代哈希表

    HSCAN Key Cursor MATCH Match COUNT Count
