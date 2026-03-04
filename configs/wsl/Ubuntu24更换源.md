# WSL Ubuntu 24 更换下载源

Ubuntu 24.04 代号为 **noble**，以下将默认 apt 源替换为国内镜像以加速安装。

## 1. 备份原有源

```bash
sudo cp /etc/apt/sources.list /etc/apt/sources.list.bak
```

## 2. 编辑 sources.list

```bash
sudo vim /etc/apt/sources.list
# 或
sudo nano /etc/apt/sources.list
```

清空或注释原有内容，按需选用下面某一组源（**noble** 为 24.04 代号）。

### 阿里云

```bash
deb https://mirrors.aliyun.com/ubuntu/ noble main restricted universe multiverse
deb https://mirrors.aliyun.com/ubuntu/ noble-updates main restricted universe multiverse
deb https://mirrors.aliyun.com/ubuntu/ noble-backports main restricted universe multiverse
deb https://mirrors.aliyun.com/ubuntu/ noble-security main restricted universe multiverse
```

### 清华

```bash
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ noble main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ noble-updates main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ noble-backports main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ noble-security main restricted universe multiverse
```

### 中科大

```bash
deb https://mirrors.ustc.edu.cn/ubuntu/ noble main restricted universe multiverse
deb https://mirrors.ustc.edu.cn/ubuntu/ noble-updates main restricted universe multiverse
deb https://mirrors.ustc.edu.cn/ubuntu/ noble-backports main restricted universe multiverse
deb https://mirrors.ustc.edu.cn/ubuntu/ noble-security main restricted universe multiverse
```

## 3. 一键替换（可选）

仅替换为阿里云时，可直接执行：

```bash
sudo sed -i 's|http://archive.ubuntu.com|https://mirrors.aliyun.com|g' /etc/apt/sources.list
sudo sed -i 's|http://security.ubuntu.com|https://mirrors.aliyun.com|g' /etc/apt/sources.list
```

若 WSL 默认生成的是 `deb [signed-by=...]` 格式，可先备份后重写为上述任意一组源，再执行下面步骤。

## 4. 更新索引

```bash
sudo apt update
sudo apt upgrade -y
```

## 说明

- Ubuntu 22.04 代号为 **jammy**，若为 22.04 将上述 `noble` 改为 `jammy` 即可。
- 使用 HTTPS 需系统已安装 `ca-certificates`，一般默认已装。
- 换源后若报 GPG 或 Release 错误，检查代号是否与系统版本一致：`lsb_release -cs`。
