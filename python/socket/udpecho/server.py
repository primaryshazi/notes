import socket

IP = '127.0.0.1'  # IP地址
PORT = 8080  # 端口号
BUFFER_SIZE = 1024

# 创建服务端socket
serverSock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
# 创建服务端套接字失败则退出
if serverSock.fileno() < 0:
    print('socket.socket() error')
    exit(-1)
try:
    serverSock.bind((IP, PORT))  # 绑定IP与端口号
    while True:
        message, address = serverSock.recvfrom(BUFFER_SIZE)
        serverSock.sendto(message, address)
        print(str('[server] : [{:s}] => {:s}').format(str(address), message.decode()))
except Exception as e:
    print(e)
finally:
    serverSock.close()  # 关闭服务端
