#!/bin/bash

INSTALL_PATH="/usr/local/shazi"
ENV_FILE="/etc/profile.d/shazi.sh"
TAR_GZ_SUFFIX=".tar.gz"

GIT_OPTION="git"
CMAKE_OPTION="cmake"
GDB_OPTION="gdb"
GCC_OPTION="gcc"
GO_OPTION="go"
PYTHON_OPTION="python"

GIT_PATH="./packet/git-2.31.1.tar.gz"
CMAKE_PATH="./packet/cmake-3.23.0-linux-x86_64.tar.gz"
GDB_PATH="./packet/gdb-10.2.tar.gz"
GCC_PATH="./packet/gcc-10.3.0.tar.gz"
GO_PATH="./packet/go1.18.1.linux-amd64.tar.gz"
PYTHON_PATH="./packet/Python-3.8.9.tar.gz"


# 用户校验
function UserCheck()
{
    echo -e "\033[32m 用户校验中... \033[0m"

    if [ "$(whoami)" != "root" ]; then
        echo -e "\033[31m 请使用root账户\n \033[0m"
        exit
    fi

    echo -e "\033[32m 用户校验成功 \033[0m"
}

# 安装路径校验
function InstallPathCheck () {
    echo -e "\033[32m 安装路径校验中... \033[0m"

    if [ -z ${INSTALL_PATH} ] || [ ! -e ${INSTALL_PATH} ]; then
        echo -e "\033[31m ${INSTALL_PATH} 不存在 \033[0m"
        exit
    fi

    echo -e "\033[32m 安装路径校验成功 \033[0m"
}

# 依赖安装
function DependsInstall() {
    echo -e "\033[32m 依赖安装中... \033[0m"

    yum install -y curl-devel expat-devel gettext-devel openssl-devel zlib-devel perl-ExtUtils-MakeMaker \
        bzip2-devel ncurses-devel sqlite-devel readline-devel tk-devel gdbm-devel db4-devel libpcap-devel \
        texinfo xz-devel libffi-devel gmp-devel mpfr-devel libmpc-devel

    echo -e "\033[32m 依赖安装成功 \033[0m"
}

# 安装包校验
function PacketCheck()
{
    echo -e "\033[32m 安装包 $1 校验中... \033[0m"

    if [ -z $1 ] || [ ! -e $1 ]; then
        echo -e "\033[31m $1 不存在 \033[0m"
        exit
    fi

    echo -e "\033[32m 安装包 $1 校验成功 \033[0m"
}

# 移除解压路径
function RemoveUnzipPath () {
    echo -e "\033[32m 移除 $1 解压路径中... \033[0m"

    rm -rf ${INSTALL_PATH}/$1

    echo -e "\033[32m 移除 $1 解压路径成功 \033[0m"
}

# 解压安装包
function UnzipPacket() {
    echo -e "\033[32m 解压 $1 安装包中... \033[0m"

    tar -zxf $1 -C ${INSTALL_PATH}

    if [ $? != 0 ]; then
        echo -e "\033[31m 解压 $1 安装包失败 \033[0m"
        RemoveUnzipPath $2
        exit
    fi

    echo -e "\033[32m 解压 $1 安装包成功... \033[0m"
}

######################
# 通过编译安装
# $1 基础包名
# $2 安装选项
######################
function InstallByCompile() {
    currentPath=$(pwd)

    cd ${INSTALL_PATH}/$1
    if [ $? != 0 ]; then
        echo -e "\033[31m  $1 路径不存在 \033[0m"
        exit
    fi

    ./configure $2
    if [ $? != 0 ]; then
        echo -e "\033[31m 配置 $1 安装包失败 \033[0m"
        exit
    fi

    make -j4
    if [ $? != 0 ]; then
        echo -e "\033[31m 编译 $1 安装包失败 \033[0m"
        exit
    fi

    make install
    if [ $? != 0 ]; then
        echo -e "\033[31m 安装 $1 安装包失败 \033[0m"
        exit
    fi

    cd ${currentPath}
}

######################
# 通过解压安装
# $1 基础包名
# $2 安装选项
######################
function InstallByUnzip() {
    mv -f ${INSTALL_PATH}/$1 ${INSTALL_PATH}/$2
    if [ $? != 0 ]; then
        echo -e "\033[31m 移动 $1 安装包失败 \033[0m"
        exit
    fi
}

######################
# 安装包
# $1 基础包名
# $2 安装选项
######################
function InsatllPacket() {
    echo -e "\033[32m 安装 $1 安装包中... \033[0m"

    if [ $2 == ${GIT_OPTION} ]; then
        InstallByCompile $1 "--prefix=${INSTALL_PATH}/$2"
    elif [ $2 == ${CMAKE_OPTION} ]; then
        InstallByUnzip $1 $2
    elif [ $2 == ${GDB_OPTION} ]; then
        InstallByCompile $1 "--prefix=${INSTALL_PATH}/$2"
    elif [ $2 == ${GCC_OPTION} ]; then
        InstallByUnzip $1 $2
    elif [ $2 == ${GO_OPTION} ]; then
        InstallByUnzip $1 $2
    elif [ $2 == ${PYTHON_OPTION} ]; then
        InstallByCompile $1 "--prefix=${INSTALL_PATH}/$2 --enable-optimizations"
    else
        echo -e "\033[31m 无此安装包 \033[0m"
        exit
    fi

    echo -e "\033[32m 安装 $1 安装包成功 \033[0m"
}

######################
# 配置环境变量
# $1 安装选项
######################
function ConfigEnv() {
    echo -e "\033[32m 配置 $1 环境变量中... \033[0m"

    isConfig=0

    if [ -e ${ENV_FILE} ]; then
        result=$(cat ${ENV_FILE} | grep $1)
        if [ -z "${result}" ]; then
            isConfig=1
        fi
    else
        isConfig=1
    fi

    if [ ${isConfig} == 1 ]; then
        echo "export PATH=${INSTALL_PATH}/$1/bin:"'$PATH' >> ${ENV_FILE}
    fi

    source /etc/profile

    echo -e "\033[32m 配置 $1 环境变量成功 \033[0m"
}

function main () {
    UserCheck
    InstallPathCheck
    DependsInstall

    for item in $*; do
        if [ ${item} == ${GIT_OPTION} ]; then
            packet=${GIT_PATH}
        elif [ ${item} == ${CMAKE_OPTION} ]; then
            packet=${CMAKE_PATH}
        elif [ ${item} == ${GDB_OPTION} ]; then
            packet=${GDB_PATH}
        elif [ ${item} == ${GCC_OPTION} ]; then
            packet=${GCC_PATH}
        elif [ ${item} == ${GO_OPTION} ]; then
            packet=${GO_PATH}
        elif [ ${item} == ${PYTHON_OPTION} ]; then
            packet=${PYTHON_PATH}
        else
            echo -e "\033[31m 无此安装包 \033[0m"
            continue
        fi

        dirname=$(basename ${packet} ${TAR_GZ_SUFFIX})

        PacketCheck ${packet}
        UnzipPacket ${packet} ${dirname}
        InsatllPacket ${dirname} ${item}
        ConfigEnv ${item}
        RemoveUnzipPath ${dirname}
    done
}

main $*
