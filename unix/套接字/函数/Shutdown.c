#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>

int main(int argc, char const *argv[])
{
    int tcpSock = socket(PF_INET, SOCK_STREAM, 0);
    int udpSock = socket(PF_INET, SOCK_DGRAM, 0);

    /**
     * 直接关闭指定方向的连接
     *
     * SHUT_RD      读方向
     * SHUT_WR      写方向
     * SHUT_RDWR    读写方向
     */
    shutdown(tcpSock, SHUT_RDWR);
    shutdown(udpSock, SHUT_RDWR);

    return 0;
}
