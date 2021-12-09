# Condition

## Operator

``` cmake
# 一元运算符
EXISTS          # 文件或目录存在
IS_DIRECTORY    # 目录
IS_SYMLINK      # 链接符号
IS_ABSOLUTE     # 绝对路径
COMMAND         # 命令宏或者函数
DEFINED         # 变量已定义
POLICY          # 策略存在
TARGET          # 编译目标

# 二元运算符
LESS            # 小于
GREATER         # 大于
EQUAL           # 等于
LESS_EQUAL      # 小于等于
GREATER_EQUAL   # 大于等于

STRLESS             # 小于
STRGREATER          # 大于
STREQUAL            # 等于
STRLESS_EQUAL       # 小于等于
STRGREATER_EQUAL    # 大于等于

VERSION_LESS            # 小于
VERSION_GREATER         # 大于
VERSION_EQUAL           # 等于
VERSION_LESS_EQUAL      # 小于等于
VERSION_GREATER_EQUAL   # 大于等于

MATCHES     # 正则表示式匹配
IN_LIST     # 在列表中

NOT     # 非
AND     # 与
OR      # 或
```

## if

``` cmake
cmake_minimum_required(VERSION 3.0.0)

project(MAIN)

set(VALUE 0)

if(VALUE LESS 0)
    message("less")
elseif(VALUE GREATER 0)
    message("greater")
else()
    message("equal")
endif()
```

## while

``` cmake
cmake_minimum_required(VERSION 3.0.0)

project(MAIN)

set(VALUE 0)

while(TRUE)
    if(${VALUE} EQUAL 3)
        break()
    else()
        math(EXPR VALUE "${VALUE} + 1" OUTPUT_FORMAT DECIMAL)
    endif()
    message(${VALUE})
endwhile()
```

## foreach

``` cmake
cmake_minimum_required(VERSION 3.0.0)

project(MAIN)

# 从1开始遍历至5
foreach(ITEM RANGE 5)
    message(${ITEM})
endforeach()

# 从1至5步进1
foreach(ITEM RANGE 1 5 1)
    message(${ITEM})
endforeach()

# 遍历12345
foreach(ITEM 1 2 3 4 5)
    message(${ITEM})
endforeach()
```
