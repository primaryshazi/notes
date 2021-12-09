import socket

IP = '127.0.0.1'
PORT = 8080
BUFFER_SIZE = 1024

clientSock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
if clientSock.fileno() < 0:
    print('socket.socket() error')
    exit(-1)
try:
    while True:
        message = input('Input : ')
        if message.lower() == 'q':
            raise Exception('quit')
        elif len(message) == 0:
            continue
        else:
            clientSock.sendto(message.encode(), (IP, PORT))
            message, address = clientSock.recvfrom(BUFFER_SIZE)
            print(str('[client] : [{:s}] => {:s}').format(str(address), message.decode()))
except Exception as e:
    print(e)
finally:
    clientSock.close()
