# 安装git

1. yum remove git

2. yum install -y curl-devel expat-devel gettext-devel openssl-devel zlib-devel gcc perl-ExtUtils-MakeMaker

3. mkdir /usr/local/shazi/git

4. 传入git-2.31.1.tar.gz至/usr/local/shazi/git中

5. tar -zxvf git-2.31.1.tar.gz

6. cd git-2.31.1

7. ./configure --prefix=/usr/local/shazi/git

8. make && make install
