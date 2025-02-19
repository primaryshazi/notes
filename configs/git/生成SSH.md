# 生成ssh

## ssh

    ssh-keygen -t rsa -C "your-email"
    cat ~/.ssh/id_rsa.pub
    ssh -T git@github.com

## config文件

    Host github.com
    User your-email
    Hostname ssh.github.com
    PreferredAuthentications publickey
    IdentityFile ~/.ssh/id_rsa
    Port 443
