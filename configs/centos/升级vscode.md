# 升级vscode

1. 编辑
    vim /etc/yum.repos.d/code.repo

2. 写入如下内容
    [code]
    name=Visual Studio Code
    baseurl=https://packages.microsoft.com/yumrepos/vscode
    enabled=1
    gpgcheck=1
    gpgkey=https://packages.microsoft.com/keys/microsoft.asc

3. 安装
    sudo yum install -y code
