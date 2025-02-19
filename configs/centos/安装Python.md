# 安装Python

1. yum -y install zlib-devel bzip2-devel openssl-devel ncurses-devel sqlite-devel readline-devel tk-devel gdbm-devel db4-devel libpcap-devel xz-devel libffi-devel

2. wget https://www.python.org/ftp/python/3.8.9/Python-3.8.9.tgz

3. tar -zxvf Python-3.8.9.tgz

4. cd Python-3.8.9

5. ./configure --prefix=/usr/local/shazi/python --enable-optimizations

6. make -j4  && make install

7. python3 -m pip install --upgrade pip

8. pip3 install flake8

9. pip3 install yapf
