# option

``` cmake
# 包含模块
include(CMakeDependentOption)

cmake_minimum_required(VERSION 3.0.0)

project(MAIN)

# 指定一个选项
option(A "option A" ON)
option(B "option B" OFF)

# 若选项A，B均为真则X为真，否则为假
cmake_dependent_option(X "option X" ON "A;B" OFF)
# 若选项A为真，B为假则Y为真，否则为假
cmake_dependent_option(Y "option Y" ON "A;NOT B" OFF)

message(${X})
message(${Y})
```
