# 设置cmake最低版本
cmake_minimum_required(VERSION 3.0.0)

project(MAIN)

set(LIBRARY_OUTPUT_PATH  ${CMAKE_HOME_DIRECTORY}/lib)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_HOME_DIRECTORY}/bin)

# 添加子目录
add_subdirectory(${CMAKE_HOME_DIRECTORY}/source/helloworld)
add_subdirectory(${CMAKE_HOME_DIRECTORY}/source/areyouok)
add_subdirectory(${CMAKE_HOME_DIRECTORY}/source/main)
