# exec_program

``` cmake
# 执行shell命令
exec_program(Command)

# Command       可执行程序
# Path          执行路径
# args...       输入参数
# VALUE_RESULT  执行结果
# RETURN_RESULT 返回值
exec_program(Command Path ARGS args... OUTPUT_VARIABLE VALUE_RESULT RETURN_VALUE RETURN_RESULT)
```
