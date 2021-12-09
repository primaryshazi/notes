# config_file

``` cmake
# 将config的内容替换@VAR@和${VAR}之后写入到source并
configure_file(config source)

# 仅拷贝不做替换
configure_file(config source COPYONLY)

# 仅替换@VAR@不替换${VAR}
configure_file(config source @ONLY)

# 利用反斜杠进行转义
configure_file(config source ESCAPE_QUOTES)

# 设置新行行尾符，与COPYONLY相冲突
# UNIX DOS WIN32 LF CRLF
configure_file(config source NEWLINE_STYLE UNIX)
```
