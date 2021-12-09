# include

``` cmake
# 包含cmake文件
include(filename.cmake)

# 查找${CMAKE_MODULE_PATH}/modulename.cmake文件
include(modulename)

# file.cmake不存在也不报错
include(filename.cmake OPTIONAL)
```
