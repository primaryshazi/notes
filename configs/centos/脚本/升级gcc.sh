#!/bin/bash

version=$(gcc -dumpversion)

yum install -y centos-release-scl
yum install -y devtoolset-9-gcc*

scl enable devtoolset-9 bash
source /opt/rh/devtoolset-9/enable

mv /usr/bin/gcc /usr/bin/gcc-${version}
ln -s /opt/rh/devtoolset-9/root/bin/gcc /usr/bin/gcc

mv /usr/bin/g++ /usr/bin/g++-${version}
ln -s /opt/rh/devtoolset-9/root/bin/g++ /usr/bin/g++

gcc -v
g++ -v
