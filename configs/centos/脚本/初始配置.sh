#!/bin/bash

# 添加下载源
sudo yum install -y epel-release

# 添加remi源
sudo yum install -y http://rpms.famillecollet.com/enterprise/remi-release-7.rpm

# 安装vim
sudo yum install -y vim

# 安装tree
sudo yum install -y tree

# 安装tweaks
sudo yum install -y gnome-tweaks

# 安装gcc系列
sudo yum install -y gcc gcc-c++ gdb kernel-devel

# 安装依赖
sudo yum install -y curl-devel expat-devel gettext-devel openssl-devel zlib-devel perl-ExtUtils-MakeMaker \
    bzip2-devel ncurses-devel sqlite-devel readline-devel tk-devel gdbm-devel db4-devel libpcap-devel \
    texinfo xz-devel libffi-devel gmp-devel mpfr-devel libmpc-devel

# 安装ntfs
sudo yum install -y ntfs-3g

# 中文输入法，安装完重启生效
sudo yum install -y ibus-libpinyin.x86_64

# 更新firefox
sudo yum update -y firefox

# 安装字体
sudo yum install -y adobe-source-code-pro-fonts

# 配置vim
cat > ~/.vimrc << EOF

set nocompatible

syntax on           " 自动语法高亮

set number          " 显示行号
set shiftwidth=4    " 设定 << 和 >> 命令移动时的宽度为 4
set softtabstop=4   " 使得按退格键时可以一次删掉 4 个空格
set tabstop=4       " 设定 tab 长度为 4
set autoindent      " 开启自动缩进
set smartindent     " 开启新行时使用智能自动缩进
set cindent         " c风格缩进

EOF
