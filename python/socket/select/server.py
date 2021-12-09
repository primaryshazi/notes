import socket
import select

IP = '127.0.0.1'  # IP地址
PORT = 8080  # 端口号
BUFFER_SIZE = 1024

# 创建服务端socket
serverSock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# 创建服务端套接字失败则退出
if serverSock.fileno() < 0:
    print('socket.socket() error')
    exit(-1)

readRegister = [serverSock]

try:
    serverSock.bind((IP, PORT))  # 绑定IP与端口号
    serverSock.listen(5)  # 监听队列最大为5
    while True:
        readEventSock, writeEventSock, errorEventSock = select.select(readRegister, [], [], 5)
        if len(readEventSock) == 0:
            print('timeout...')
            continue
        for eventSock in readEventSock:
            if eventSock is serverSock:
                clientSock, address = serverSock.accept()  # 等待连接
                readRegister.append(clientSock)
                print(str('[server] : connect {:d}').format(clientSock.fileno()))
            else:
                try:
                    message = eventSock.recv(BUFFER_SIZE)  # 获取客户端消息返回bytes
                except Exception as recvExcept:
                    print(recvExcept)
                else:
                    if not message:  # 对方正常关闭会传输空字节
                        print(str('[server] : disconnect {:d}').format(eventSock.fileno()))
                        readRegister.remove(eventSock)
                        eventSock.close()
                    else:
                        print(str('[server] : [{:d}] => {:s}').format(eventSock.fileno(), message.decode()))
                        eventSock.sendall(message)  # 向客户端发送消息保证全部发送
except Exception as e:
    print(e)
finally:
    serverSock.close()  # 关闭服务端
