import socket

IP = '127.0.0.1'  # IP地址
PORT = 8080  # 端口号
BUFFER_SIZE = 1024

# 创建服务端socket
serverSock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# 创建服务端套接字失败则退出
if serverSock.fileno() < 0:
    print('socket.socket() error')
    exit(-1)
try:
    serverSock.bind((IP, PORT))  # 绑定IP与端口号
    serverSock.listen(5)  # 监听队列最大为5
    while True:
        clientSock, address = serverSock.accept()  # 等待连接
        print(str('[server] : connect {:d}').format(clientSock.fileno()))

        while True:
            try:
                message = clientSock.recv(BUFFER_SIZE)  # 获取客户端消息返回bytes
            except Exception as rwExcept:  # 客户端异常退出会导致异常
                print(rwExcept)
                break
            else:
                if not message:  # 对方正常关闭会传输空字节
                    break
                print(str('[server] : [{:d}] => {:s}').format(clientSock.fileno(), message.decode()))
                clientSock.sendall(message)  # 向客户端发送消息保证全部发送

        print(str('[server] : disconnect {:d}').format(clientSock.fileno()))
        clientSock.close()  # 关闭客户端
except Exception as e:
    print(e)
finally:
    serverSock.close()  # 关闭服务端
