# variable_watch

``` cmake
# 监视变量的变化
variable_watch(VALUE_RESULT)

# 命令变化执行指定命令
function(Print variable access value current_list_file stack)
    message(STATUS "${variable} ${access} ${value} ${current_list_file} ${stack}")
endfunction()

variable_watch(VALUE_RESULT Print)
```
