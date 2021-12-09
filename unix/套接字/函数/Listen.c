#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char const *argv[])
{
    int tcpSock = socket(PF_INET, SOCK_STREAM, 0);

    struct sockaddr_in tcpAddr;

    memset(&tcpAddr, 0, sizeof(tcpAddr));
    tcpAddr.sin_family = AF_INET;
    tcpAddr.sin_port = htons(8080);
    tcpAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (bind(tcpSock, (const struct sockaddr *)&tcpAddr, sizeof(tcpAddr)) < 0)
    {
        printf("bind() error\n");
        exit(EXIT_FAILURE);
    }

    /**
     * 服务端专用，监听客户端的连接，在调用accept之前的排队连接数为5
     * 排队队列分为已完成连接队列和未完成连接队列
     */
    if (listen(tcpSock, 5) < 0)
    {
        printf("listen() error\n");
        exit(EXIT_FAILURE);
    }

    close(tcpSock);

    return 0;
}
