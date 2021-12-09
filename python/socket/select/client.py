import socket

IP = '127.0.0.1'
PORT = 8080
BUFFER_SIZE = 1024

clientSock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
if clientSock.fileno() < 0:
    print('socket.socket() error')
    exit(-1)
try:
    clientSock.connect((IP, PORT))  # 连接服务端
    while True:
        message = input('Input : ')
        if message.lower() == 'q':
            raise Exception('quit')
        elif len(message) == 0:
            continue
        else:
            value = clientSock.sendall(message.encode())  # 向服务端发送信息
            message = clientSock.recv(BUFFER_SIZE)  # 从服务端接收信息
            print(str('[client] : {:s}').format(message.decode()))
except Exception as e:
    print(e)
finally:
    clientSock.close()
