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

    /**
     * 将协议地址赋予一个套接字；IP与端口号可以不指定，由内核分配
     *
     * 通配IP，端口为0      内核分配IP和端口号
     * 统配IP，端口不为0    内核分配IP，进程指定端口
     * 固定IP，端口为0      进程指定IP，内核分配端口
     * 固定IP，端口不为0    进程指定IP和端口
     *
     * 服务器不指定IP，由客户端的SYN的目的地址获取IP
     * 客户端不指定IP，由外出网络接口来选择源IP
     * 未指定端口，需要通过getsockname()获取协议地址
     */
    if (bind(tcpSock, (const struct sockaddr *)&tcpAddr, sizeof(tcpAddr)) < 0)
    {
        printf("bind() error\n");
        exit(EXIT_FAILURE);
    }

    close(tcpSock);

    return 0;
}
