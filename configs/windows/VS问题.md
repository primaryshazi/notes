# VS问题

## 无法下载安装

1. 查找aka.ms的对应IP

2. 在hosts文件中添加如下一行
    IP aka.ms

3. ipconfig /flushdns

## 无法登录

    修改首选DNS为4.2.2.2

## 拓展下载缓慢

1. https://www.ipaddress.com/ 查找如下域名IP
    download.visualstudio.microsoft.com

2. 在hosts文件中添加如下一行
    IP download.visualstudio.microsoft.com

3. ipconfig /flushdns
