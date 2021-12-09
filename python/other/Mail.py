import smtplib
from email.mime.text import MIMEText

# 163邮箱服务器地址
MAIL_HOST = 'smtp.163.com'
# 163用户名
MAIL_USER = '****@163.com'
# 密码(部分邮箱为授权码)
MAIL_PASS = '****'
# 邮件发送方邮箱地址
MAIL_SENDER = '****@163.com'
# 邮件接受方邮箱地址，注意需要[]包裹，这意味着你可以写多个邮件地址群发
MAIL_RECEIVERS = ['****@qq.com']

# 邮件内容设置
message = MIMEText('content', 'plain', 'utf-8')
# 邮件主题
message['Subject'] = 'title'
# 发送方信息
message['From'] = MAIL_SENDER
# 接受方信息
message['To'] = MAIL_RECEIVERS[0]

# 登录并发送邮件
try:
    smtpObj = smtplib.SMTP()
    # 连接到服务器
    smtpObj.connect(MAIL_HOST, 25)
    # 登录到服务器
    smtpObj.login(MAIL_USER, MAIL_PASS)
    # 发送
    smtpObj.sendmail(MAIL_SENDER, MAIL_RECEIVERS, message.as_string())
    # 退出
    smtpObj.quit()
    print('success')
except smtplib.SMTPException as e:
    print('error', e)
