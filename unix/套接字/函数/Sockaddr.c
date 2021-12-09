#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char const *argv[])
{
    int tcpSock = socket(PF_INET, SOCK_STREAM, 0);

    // sockaddr与sockaddr_in内存结构相同可以互相转换
    struct sockaddr_in tcpAddr;

    memset(&tcpAddr, 0, sizeof(tcpAddr));
    tcpAddr.sin_family = AF_INET;   // 设置协议族
    tcpAddr.sin_port = htons(8080); // 设置端口号
    /**
     * htonl(INADDR_ANY)    设置任意IP地址
     */
    tcpAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // 设置IP地址

    close(tcpSock);

    return 0;
}
