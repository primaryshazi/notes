# 安装gcc

1. 安装依赖 yum install -y gmp-devel mpfr-devel libmpc-devel

2. mkdir /usr/local/shazi/gcc

3. 传入gcc-10.3.0.tar.gz至/usr/local/shazi/gcc中

4. tar -zxvf gcc-10.3.0.tar.gz

5. cd gcc-10.3.0

6. ./configure --prefix=/usr/local/shazi/gcc --enable-checking=release --enable-languages=c,c++ --disable-multilib --enable-threads=posix

7. make -j4 && make install

8. cp /usr/local/shazi/gcc/lib64/libstdc++.so.6.0.28 /usr/lib64/

9. cd /usr/lib64/

10. rm -rf libstdc++.so.6

11. ln -s libstdc++.so.6.0.28 libstdc++.so.6
