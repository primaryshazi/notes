#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

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

    struct sockaddr_in thisAddr;
    struct sockaddr_in thatAddr;
    socklen_t thisSockLength = sizeof(thisAddr);
    socklen_t thatSockLength = sizeof(thatAddr);
    memset(&thisAddr, 0, thisSockLength);
    memset(&thatAddr, 0, thatSockLength);

    // 获取本机协议地址
    if (getsockname(serverSock, (struct sockaddr *)&thisAddr, &thisSockLength) < 0)
    {
        printf("getsockname() error");
    }
    else
    {
        printf("family : %d  ip : %s  port : %d\n", thisAddr.sin_family, inet_ntoa(thisAddr.sin_addr),
               ntohs(thisAddr.sin_port));
    }

    // 获取对端协议地址
    if (getpeername(serverSock, (struct sockaddr *)&thatAddr, &thatSockLength) < 0)
    {
        printf("%s\n", strerror(errno));
        printf("getpeername() error\n");
    }
    else
    {
        printf("family : %d  ip : %s  port : %d\n", thatAddr.sin_family, inet_ntoa(thatAddr.sin_addr),
               ntohs(thatAddr.sin_port));
    }

    close(serverSock);

    return 0;
}
