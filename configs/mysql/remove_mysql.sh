#!/bin/bash

BASE_PATH="/usr/local/shazi/mysql"
ENV_PATH="/etc/profile.d/shazi.sh"

if [ "$(whoami)" != "root" ]; then
    echo -e "\033[31m 请使用root账户\n \033[0m"
    exit
fi

echo -e "\033[32m 卸载mysql... \033[0m"

# 停止mysqld服务
systemctl stop mysqld
chkconfig --del mysqld

# 移除mysql用户
if [ $(grep -Ec "^mysql" /etc/group) != 0 ]; then
    userdel -rf mysql
fi

# 删除mysql安装包
for item in $(rpm -qa | grep mysql); do
    rpm -e --nodeps $item
done

# 移除mysql文件
rm -rf ${BASE_PATH}
rm -rf /usr/bin/mysql*
rm -rf /usr/lib/mysql*
rm -rf /var/lib/mysql*
rm -rf /usr/lock/subsys/mysql*
rm -rf /etc/my.cnf*
rm -rf /etc/init.d/mysql*

# 移除mysql环境变量
sed -i "/mysql/d" ${ENV_PATH}
source /etc/profile

echo -e "\033[32m 卸载mysql成功 \033[0m"
