# 安装nodejs

## windows

1. 安装nodejs，安装路径假定为"D:\nodejs"

2. 在安装路径下创建 node_global 和 node_cache 两个文件夹

3. 配置模块路径 npm config set prefix "D:\nodejs\node_global"

4. 配置cache路径 npm config set cache "D:\nodejs\node_cache"

5. 配置配置源 npm config set registry=http://registry.npm.taobao.org

6. 创建系统变量 NODE_PATH = "D:\nodejs\node_modules"

7. 添加 "D:\nodejs\node_global" 到PATH

## linux


