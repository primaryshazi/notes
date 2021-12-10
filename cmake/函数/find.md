# find

``` cmake
# 查找文件完整路径于${VALUE_RESULT}
find_file(VALUE_RESULT name)

# 查找库完整路径于${VALUE_RESULT}
find_library(VALUE_RESULT name)

# 查找可执行程序完整路径于${VALUE_RESULT}
find_program(VALUE_RESULT name)

# 查找文件完整路径于${VALUE_RESULT}
find_path(VALUE_RESULT name)

# names... 文件可能的多个名称
# paths... 可能的多个路径
# NO_DEFAULT_PATH   只在指定路径下搜索
find_file(VALUE_RESULT NAMES names... PATHS paths... NO_DEFAULT_PATH)


# 查找模块
find_package(CURL)

# 输出模块是否找到
message(STATUS ${CURL_FOUND})

# 输出模块完成路径
message(STATUS ${CURL_LIBRARIES})

#输出模块所在目录
message(STATUS ${CURL_INCLUDE_DIRS})
```
