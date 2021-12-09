# file

``` cmake
# 获取${CMAKE_HOME_DIRECTORY}下的所有文件储存于${FILE_LIST}
file(GLOB FILE_LIST ${CMAKE_HOME_DIRECTORY}/*)

# 递归获取${CMAKE_HOME_DIRECTORY}下的所有文件储存于${FILE_LIST}
file(GLOB_RECURSE FILE_LIST ${CMAKE_HOME_DIRECTORY}/*)

# 写入"Hello World!"到filename
file(WRITE filename "Hello World!")

# 追加"Are You OK?"到filename
file(APPEND filename "Are You OK?")

# 从filename读取到${VARIABLE_DATA}
file(READ filename VARIABLE_DATA)

# 将filename用MD5加密至${VARIABLE_DATA}
# MD5 SHA1 SHA224 SHA256 SHA384 SHA512
file(MD5 filename VARIABLE_DATA)

# 获取文件最后修改的时间戳
file(TIMESTAMP filename VARIABLE_DATA)
file(TIMESTAMP filename VARIABLE_DATA "%Y-%m-%d %H:%M:%S")

# 从文件中读取每一行数据到${VARIABLE_DATA}
file(STRINGS filename VARIABLE_DATA)

# 类似于touch命令
file(TOUCH filename)
file(TOUCH_NOCREATE filename)

# 重命名文件
file(RENAME filename filename_bak)

# 删除文件或目录
file(REMOVE dirname)

# 递归删除文件或目录
file(REMOVE_RECURSE dirname)

# 创建目录
file(MAKE_DIRECTORY dirname)

# 获取文件大小
file(SIZE filename VARIABLE_DATA)

# 创建链接
file(CREATE_LINK filename filename_link)

# 读取链接路径
file(READ_SYMLINK filename_link VARIABLE_DATA)
```
