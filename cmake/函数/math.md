# math

``` cmake
cmake_minimum_required(VERSION 3.0.0)

project(MAIN)

set(MATH_EXPRESSION "010 * 0x20 * 30")

# 输出10进制数
math(EXPR RESULT_VALUE ${MATH_EXPRESSION} OUTPUT_FORMAT DECIMAL)
message(${RESULT_VALUE})

# 输出16进制
math(EXPR RESULT_VALUE ${MATH_EXPRESSION} OUTPUT_FORMAT HEXADECIMAL)
message(${RESULT_VALUE})
```
