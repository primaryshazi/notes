# string

``` cmake
cmake_minimum_required(VERSION 3.0.0)

project(MAIN)

set(STR "ABCDEFG")

# 正向查找子串第一次出现的位置的索引，不存在返回-1
string(FIND ${STR} "CD" INDEX)

# 反向向查找子串第一次出现的位置的索引，不存在返回-1
string(FIND ${STR} "CD" INDEX REVERSE)

# 将STR中的CD替换成cd
string(REPLACE "CD" "cd" STR_1 ${STR})

string(REGEX REPLACE "([A-Z]+)" "\\1\\1" STR_2 ${STR})

# 返回第一次正则表达式匹配项
string(REGEX MATCH "[CD]+" STR_3 ${STR}${STR})

# 返回所有正则表达式匹配项
string(REGEX MATCHALL "[CD]+" STR_4 ${STR}${STR})

# 字符串后追加HIJ
string(APPEND STR_5 210)

# 字符串前添加abc
string(PREPEND STR_5 012)

# 将a，b，c拼接
string(CONCAT STR_6 a b c)

# 输入参数用-连接起来
string(JOIN "-" STR_7 ${STR} ${STR})

# 转化为小写
string(TOLOWER ${STR} STR_8)

# 转化为大写
string(TOUPPER ${STR} STR_9)

# 返回字符串的长度
string(LENGTH ${STR} STR_LEN)

# 返回从1号元素起，共3个字符的字符串
string(SUBSTRING ${STR} 1 3 STR_SUB)

# 移除前后空白字符
string(STRIP ${STR} STR_10)

# 重复字符串两次
string(REPEAT ${STR} 2 STR_11)

#[[
COMPARE : EQUAL
COMPARE : NOTEQUAL
COMPARE : LESS
COMPARE : GREATER
COMPARE : LESS_EQUAL
COMPARE : GREATER_EQUAL
]]
# 字符串比较
string(COMPARE LESS ${STR} ${STR} RESULT)

#[[
MD5
SHA1
SHA224
SHA256
SHA384
SHA512
SHA3_224
SHA3_256
SHA3_384
SHA3_512
]]
# hash散列
string(MD5 STR_HASH ${STR})

# 数字转换为ASCII字符
string(ASCII 48 49 50 STR_ASCII)

# 字符转换为16进制转换
string(HEX ${STR} STR_HEX)

# 随机生成长度为10，内容在"0123456789"中，随机种子为1024的字符串
string(RANDOM LENGTH 10 ALPHABET "0123456789" RANDOM_SEED 1024 STR_RANDOM)

# 获取当前时间戳，UTC可不要
string(TIMESTAMP STR_TIME "%Y-%m-%d %H:%M:%S" UTC)
```
