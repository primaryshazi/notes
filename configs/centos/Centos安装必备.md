# 安装必备

## 配置固定IP

1. 打开VMware->编辑->虚拟网络编辑器

2. 选择VMnet8，取消勾选“使用本地DHCP服务将IP地址分配给虚拟机”

3. 记录子网IP，子网掩码，网关

4. 打开控制面板->网络和Internet->网络和共享中心->更改适配器设置->VMnet8->属性->Internet协议4，保证IP地址与子网IP同一网段

5. sudo vim /etc/sysconfig/network-scripts/ifcfg-ens33，修改如下信息
    BOOTPROTO=static
    ONBOOT=yes
    IPADDR=与子网IP同一网段
    NETMASK=子网掩码
    GATEWAY=网关
    DNS1=119.29.29.29
    DNS2=114.114.114.114

## 硬盘分区

1. swap
    swap
    2 * memory

2. boot
    ext4
    1024M

3. home
    ext4
    0.2 * storage

4. var
    ext4
    0.1 * storage

5. /
    ext4
    其余

## 配置终端快捷键

    名  称：Terminal
    命  令：/usr/bin/gnome-terminal
    快捷键：Ctrl+Tab

## vim配置

    "放在~下保存为.vimrc或者在/ect/vimrc中添加

    set nocompatible

    syntax on           " 自动语法高亮

    set number          " 显示行号
    set shiftwidth=4    " 设定 << 和 >> 命令移动时的宽度为 4
    set softtabstop=4   " 使得按退格键时可以一次删掉 4 个空格
    set tabstop=4       " 设定 tab 长度为 4
    set autoindent      " 开启自动缩进
    set smartindent     " 开启新行时使用智能自动缩进
    set cindent         " c风格缩进
