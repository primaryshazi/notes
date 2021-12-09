# Key

## 删除键

    DEL Key

## 序列化键

    DUMP Key

## 检查键是否存在

    EXISTS Key

## 设置Key超时时间

    # 秒数
    EXPIRE Key Second

    # 毫秒
    PEXPIRE key Millisecond

    # UNIX时间秒数记
    EXPIREAT Key Timestamp

    # UNIX时间毫秒记
    PEXPIREAT Key Mill-Timestamp

## 获取超时时间

    # 秒数记
    TTL Key

    # 毫秒记
    PTTL Key

## 移除超时时间

    PERSIST Key

## 查找符合模式的键

    KEYS Pattern

## 移动键至数据库

    MOVE Key Datebase

## 从当前库中随机返回一个键

    RANDOMKEY

## 修改键的名称

    # 重命名
    RENAME Key NewKey

    # 键存在才重命名
    RENAMENX Key NewKey

## 返回键的类型

    TYPE Key

## 迭代数据库中所有的键

    # 返回下次迭代的序号

    # 从序号Cursor开始迭代，默认迭代10个
    SCAN Cursor

    # 从序号Cursor开始迭代指定匹配项，默认迭代10个
    SCAN Cursor MATCH Match

    # 从序号Cursor开始迭代指定匹配项，迭代0个
    SCAN Cursor MATCH Match COUNT Count
