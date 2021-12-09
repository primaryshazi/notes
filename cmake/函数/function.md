# function

``` cmake
cmake_minimum_required(VERSION 3.0.0)

project(MAIN)

# 定义函数
function(Print)
    message("Are you OK?")
endfunction()

# 调用函数
Print()

# 定义函数
function(Println argument)
    message(${argument})
endfunction()

# 调用函数
Println("Hello World!")
```
