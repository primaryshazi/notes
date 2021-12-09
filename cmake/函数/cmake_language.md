# cmake_language

``` cmake
cmake_minimum_required(VERSION 3.0.0)

project(MAIN)

# message(STATUS "status")
set(MESSAGE_CMD message)
cmake_language(CALL ${MESSAGE_CMD} STATUS "status")

# 执行cmake脚本
cmake_language(EVAL CODE "
    if (TRUE)
        message(TRUE)
    else()
        message(FALSE)
    endif()
")
```
