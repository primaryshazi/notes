# 安装docker

1. 卸载旧版本docker sudo yum remove docker docker-client docker-client-latest docker-common docker-latest docker-latest-logrotate docker-logrotate docker-engine

2. 安装驱动包 sudo yum install -y yum-utils device-mapper-persistent-data lvm2

3. 安装阿里云镜像 sudo yum-config-manager --add-repo http://mirrors.aliyun.com/docker-ce/linux/centos/docker-ce.repo

4. 安装最新版docker sudo yum install -y docker-ce docker-ce-cli containerd.io

5. 或者安装指定版本docker sudo yum install -y docker-ce-VERSION docker-ce-cli-VERSION containerd.io

6. 自启docker sudo systemctl enable docker

7. 启动docker sudo systemctl start docker
