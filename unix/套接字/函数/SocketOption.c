#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>

int main(int argc, char const *argv[])
{
    int serverSock = socket(PF_INET, SOCK_STREAM, 0);

    int option = 1;

    /**
     * __fd         socket描述符
     * __level      选项级别
     * __optname    选项名
     * __optval     选项值
     * __optlen     选项值的长度
     *
     * SOL_SOCKET       基本套接字
     * IPPROTO_IP       IPv4套接字
     * IPPROTO_IPV6     IPv6套接字
     * IPPROTO_TCP      TCP套接字
     */
    if (setsockopt(serverSock, SOL_SOCKET, SO_REUSEADDR, (void *)&option, sizeof(option)) < 0)
    {
        puts("setsockopt() error");
        exit(EXIT_FAILURE);
    }

    int optionValue = 0;
    socklen_t optionLen = 0;

    if (getsockopt(serverSock, SOL_SOCKET, SO_REUSEADDR, (void *)&optionValue, &optionLen) < 0)
    {
        puts("getsockopt() error");
        exit(EXIT_FAILURE);
    }

    printf("option : %d\n", optionValue);
    printf("length : %d\n", optionLen);

    close(serverSock);

    return 0;
}
