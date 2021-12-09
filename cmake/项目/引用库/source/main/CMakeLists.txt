cmake_minimum_required(VERSION 3.0.0)

add_executable(main main.cpp)
add_dependencies(main areyouok helloworld)

# 指定头文件包含目录
target_include_directories(main PRIVATE ${CMAKE_HOME_DIRECTORY}/source/areyouok ${CMAKE_HOME_DIRECTORY}/source/helloworld)

# 指定链接库包含目录
target_link_directories(main PRIVATE ${CMAKE_HOME_DIRECTORY}/lib)

# 指定main的依赖库
target_link_libraries(main areyouok helloworld)
