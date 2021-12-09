# 设置cmake最低版本
cmake_minimum_required(VERSION 3.0.0)

# 设置项目名
project(MAIN)

# 指定头文件路径
include_directories(./include)

# 将./src路径下的所有文件添加到SRC_LIST中
aux_source_directory(./src SRC_LIST)

# 指定静态库生成路径
set(LIBRARY_OUTPUT_PATH ${CMAKE_HOME_DIRECTORY}/lib)

# 生成静态库
add_library(hello STATIC ${SRC_LIST})
