#!/bin/bash

BASE_PATH="/usr/local/shazi/mysql"
ENV_PATH="/etc/profile.d/shazi.sh"
PASS_WORD="asdf"
MYSQL_TAR="$1"
MYSQL_GZ_SUFFIX=".tar.gz"
MYSQL_XZ_SUFFIX=".tar.xz"

if [ "$(whoami)" != "root" ]; then
    echo -e "\033[31m 请使用root账户\n \033[0m"
    exit
fi

if [ -z ${MYSQL_TAR} ] || [ ! -e ${MYSQL_TAR} ]; then
    echo -e "\033[31m 请输入正确安装包路径 \033[0m"
    exit
fi

# 解压mysql
echo -e "\033[32m 解压${MYSQL_TAR}... \033[0m"

if [[ -n $(echo ${MYSQL_TAR} | grep ${MYSQL_GZ_SUFFIX}) ]]; then
    mkdir ${BASE_PATH} || exit
    tar -xzf ${MYSQL_TAR} || exit
    mv ${MYSQL_TAR%.*.*}/* ${BASE_PATH} || exit
    rm -rf ${MYSQL_TAR%.*.*}
elif [[ -n $(echo ${MYSQL_TAR} | grep ${MYSQL_XZ_SUFFIX}) ]];then
    mkdir ${BASE_PATH} || exit
    xz -dk ${MYSQL_TAR} || exit
    tar -xf ${MYSQL_TAR%.*} || exit
    mv ${MYSQL_TAR%.*.*}/* ${BASE_PATH} || exit
    rm -rf ${MYSQL_TAR%.*}
    rm -rf ${MYSQL_TAR%.*.*}
else
    echo -e "\033[31m 文件格式错误 \033[0m"
    exit
fi
echo -e "\033[32m 解压${MYSQL_TAR}成功 \033[0m"

# 赋予必要权限
echo -e "\033[32m 创建mysql用户并赋予必要权限... \033[0m"
if [ $(grep -Ec "^mysql" /etc/group) == 0 ]; then
    useradd -r mysql
fi
cd ${BASE_PATH} || exit
mkdir data
chown -R root:mysql ${BASE_PATH}/*
echo -e "\033[32m 创建mysql用户并赋予必要权限成功 \033[0m"

# 安装mysql
echo -e "\033[32m 安装mysql... \033[0m"
${BASE_PATH}/bin/mysqld --initialize --lower-case-table-names=1 --user=mysql --basedir=${BASE_PATH} --datadir=${BASE_PATH}/data

# 添加mysql到系统服务
cp ${BASE_PATH}/support-files/mysql.server /etc/init.d/mysqld
chkconfig --add mysqld

# 更改配置文件
echo "[mysqld]
basedir = ${BASE_PATH}
datadir = ${BASE_PATH}/data
socket = /tmp/mysql.sock
user = mysql
# 端口号为3306
port = 3306
# 默认字符集为utf8mb4
character-set-server = utf8mb4
# 默认储存引擎为InnoDB
default_storage_engine = InnoDB
# 允许最大连接数
max_connections = 256
# 允许连接失败的次数
max_connect_errors = 128
# 输出路径不限
secure_file_priv =
# 不区分大小写
lower_case_table_names = 1
# 开启事件
event_scheduler=ON
# 禁用符号链接
symbolic-links=0
# 跳过验证
skip-grant-tables

[client]
port = 3306
default-character-set = utf8mb4
socket = /tmp/mysql.sock

[mysql]
# 开启自动补全
auto-rehash

[mysqld_safe]
# 指定错误日志路径
log-error = /var/log/mysqld.log
# 指定pid路径
pid-file = /var/run/mysqld/mysqld.pid
" > /etc/my.cnf

# 设置环境变量
if [ $(grep "mysql" ${ENV_PATH} | wc -l) -eq 0 ]; then
    echo "export PATH=${BASE_PATH}/bin:"'$PATH' >> ${ENV_PATH}
fi
source /etc/profile
systemctl restart mysqld.service
echo -e "\033[32m 安装mysql成功 \033[0m"

# 修改密码
echo -e "\033[32m 修改密码... \033[0m"
${BASE_PATH}/bin/mysql -uroot -e "FLUSH privileges;
ALTER USER 'root'@'localhost' IDENTIFIED WITH mysql_native_password BY '${PASS_WORD}';
USE mysql;
UPDATE user SET host = '%' WHERE user = 'root';"

# 关闭跳过验证
sed -i 's/skip-grant-tables/\#&/' /etc/my.cnf
systemctl restart mysqld.service
echo -e "\033[32m 修改密码成功 \033[0m"
