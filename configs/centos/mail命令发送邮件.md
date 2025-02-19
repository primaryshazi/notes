# mail命令发送邮件

1. 安装服务
    sudo yum install -y mailx mail sendmail

2. 以网页形式登陆邮箱，开启发送邮箱的POP3/IMAP/SMTP服务

3. vim /etc/mail.rc，在文件尾加入

```
# 发送者邮箱
set from=your-email
# 邮箱服务地址
set smtp=smtp.163.com
# 发送者用户名
set smtp-auth-user=your-name
# 授权码
set smtp-auth-password=your-code
# 邮件认证的方式
set smtp-auth=login
# 忽略验证
set ssl-verify=ignore
set nss-config-dir=/etc/maildbs/
```

4. 发送邮箱
    echo "内容" | mail -s "标题" your-email
