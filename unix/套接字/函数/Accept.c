#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char const *argv[])
{
    int serverSock = socket(PF_INET, SOCK_STREAM, 0);

    struct sockaddr_in serverAddr;

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (bind(serverSock, (const struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
    {
        printf("bind() error\n");
        exit(EXIT_FAILURE);
    }

    if (listen(serverSock, 5) < 0)
    {
        printf("listen() error\n");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in clientAddr;
    socklen_t sockLength = sizeof(clientAddr);
    // 返回连接服务器的客户端的协议地址
    int clientSock = accept(serverSock, (struct sockaddr *)&clientAddr, &sockLength);

    if (clientSock < 0)
    {
        printf("accept() error\n");
        exit(EXIT_FAILURE);
    }

    close(serverSock);

    return 0;
}
