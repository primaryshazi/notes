# message

``` cmake
cmake_minimum_required(VERSION 3.0.0)

message("This message is")                      # 普通信息
message(NOTICE "This message is NOTICE")        # 普通信息
message(STATUS "This message is STATUS")        # 一般状态信息
message(WARNING "This message is WARNING")      # 告警信息，继续处理
message(AUTHOR_WARNING "This message is AUTHOR_WARNING")    # 告警dev信息，继续处理
message(DEPRECATION "This message is DEPRECATION")          # 告警弃用信息，继续处理
message(VERBOSE "This message is VERBOSE")      # 详细信息，不显示
message(DEBUG "This message is DEBUG")          # debug信息
message(TRACE "This message is TRACE")          # 暂时细度信息
message(SEND_ERROR "This message is SEND_ERROR")            # 错误信息，继续处理停止生成
message(FATAL_ERROR "This message is FATAL_ERROR")          # 错误信息，停止处理以及生成
```
