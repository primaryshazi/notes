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

    // TCP客户端用于连接TCP服务端套接字，若连接失败需关闭该套接字；此时触发三次握手过程
    if (connect(tcpSock, (const struct sockaddr *)&tcpAddr, sizeof(tcpAddr)) < 0)
    {
        printf("connect() error\n");
        exit(EXIT_FAILURE);
    }

    close(tcpSock);

    return 0;
}
