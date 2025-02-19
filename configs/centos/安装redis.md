# 安装redis

1. mkdir -p /usr/local/shazi/redis /usr/local/shazi/redis/conf /usr/local/shazi/redis/data

2. 传入redis-6.2.4至/usr/local/shazi/redis中

3. tar -zxvf redis-6.2.4.tar.gz

4. cd redis-6.2.4

5. make install PREFIX=/usr/local/shazi/redis

6. cp ./redis.conf /usr/local/shazi/redis/conf/

7. sed -i 's/daemonize no/daemonize yes/g' /usr/local/shazi/redis/conf/redis.conf

8. sed -i 's/dir .\//dir \/usr\/local\/shazi\/redis\/data/g' /usr/local/shazi/redis/conf/redis.conf

9. echo "export PATH=/usr/local/shazi/redis/bin:"'$PATH' >> /etc/profile.d/shazi.sh

10. 设置开机启动

``` shell
echo > /etc/systemd/system/redis.service << EOF
[Unit]
Description=redis-server
After=network.target

[Service]
Type=forking
ExecStart=/usr/local/shazi/redis/bin/redis-server /usr/local/shazi/redis/conf/redis.conf
PrivateTmp=true

[Install]
WantedBy=multi-user.target
EOF
```

11. systemctl daemon-reload

12. systemctl enable redis.service

13. systemctl start redis.service
