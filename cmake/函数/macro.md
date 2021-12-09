# macro

``` cmake
cmake_minimum_required(VERSION 3.0.0)

project(MAIN)

# 定义宏
macro(Print)
    message("Are you OK?")
endmacro()

# 调用宏
Print()

# 定义宏
macro(Println argument)
    message(${argument})
endmacro()

# 调用宏
Println("Hello World!")
```
