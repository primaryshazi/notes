# list

``` cmake
cmake_minimum_required(VERSION 3.0.0)

project(MAIN)

# 二者等效
set(LIST_1 1 2 3 4 5)
set(LIST_2 "1;2;3;4;5")

# 获取LIST_1长度
list(LENGTH LIST_1 LIST_LEN)

# 获取LIST_1的0号和2号元素
list(GET LIST_1 0 2 ITEM)

# 返回值为3的索引，不存在返回-1
list(FIND LIST_1 3 INDEX)

# 在每个元素用空白字符连接起来
list(JOIN LIST_1 " " LIST_3)

# 返回从1号元素起，共2个元素组成的子序列
list(SUBLIST LIST_1 1 2 LIST_4)

# 移除最后一个元素，并将该值赋值于ITEM，ITEM可不要
list(POP_BACK LIST_1 ITEM)

# 移除第一个元素，并将该值赋值于ITEM，ITEM可不要
list(POP_FRONT LIST_1 ITEM)

# 过滤元素2或3
list(FILTER LIST_1 INCLUDE REGEX 2|3)

# 过滤元素非2或3
list(FILTER LIST_1 EXCLUDE REGEX 2|3)

# 尾部追加元素6，7，8
list(APPEND LIST_1 6 7 8)

# 头部追加元素1，2，3，4，5
list(PREPEND LIST_1 1 2 3 4 5)

# 在0号位置之前插入元素0
list(INSERT LIST_1 0 0)

# 移除序列中所有的元素8
list(REMOVE_ITEM LIST_1 8)

# 移除0号元素
list(REMOVE_AT LIST_1 0)

# 移除所有重复选项
list(REMOVE_DUPLICATES LIST_1)

# 每个元素后添加空格
list(TRANSFORM LIST_1 APPEND " ")

# 每个元素前添加空格
list(TRANSFORM LIST_1 PREPEND " ")

# 每个元素小写
list(TRANSFORM LIST_1 TOLOWER)

# 每个元素大写
list(TRANSFORM LIST_1 TOUPPER)

# 每个元素删除前后空白字符
list(TRANSFORM LIST_1 STRIP)

# 正则表达式替换
list(TRANSFORM LIST_1 REPLACE "\([0-9]\)" "\\1 " )

#[[
# 指定索引位置转换
list(TRANSFORM <list> <ACTION> AT <index>)

# 指定范围转换
list(TRANSFORM <list> <ACTION> FOR <start> <stop> [<step>])

# 指定正则匹配项替换
list(TRANSFORM <list> <ACTION> REGEX <regular_expression>)
]]

# 反转序列
list(REVERSE LIST_1)

#[[
COMPARE : STRING            # 字符串模式
COMPARE : FILE_BASENAME     # 全路径模式
COMPARE : NATURAL           # 自然排序
]]
#[[
CASE : SENSITIVE            # 区分大小写
CASE : INSENSITIVE          # 不区分大小写
]]
#[[
ORDER : ASCENDING           # 升序排序
ORDER : DESCENDING          # 降序排序
]]
# 按照字符串形式，区分大小写，升序排序
list(SORT LIST_1 COMPARE STRING CASE SENSITIVE ORDER ASCENDING)
```
