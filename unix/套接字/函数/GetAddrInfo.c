#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define __USE_POSIX

#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char const *argv[])
{
    const char *ip = "www.baidu.com";
    struct addrinfo hints;          // 期望选项
    struct addrinfo *result = NULL; // 返回结果

    memset(&hints, 0, sizeof(hints));

    hints.ai_family = AF_INET;       // IPv4协议族
    hints.ai_protocol = 0;           // 任何协议
    hints.ai_socktype = SOCK_STREAM; // 数据流

    /**
     * => __name        主机名或地址串
     * => __service     端口号或服务名称
     * => __req         期望返回信息选项
     * => __pai         返回信息
     */
    if (getaddrinfo(ip, NULL, &hints, &result) < 0)
    {
        puts("getaddrinfo() error");
        exit(EXIT_FAILURE);
    }

    for (struct addrinfo *cursor = result; cursor != NULL; cursor = cursor->ai_next)
    {
        struct sockaddr_in *addr = (struct sockaddr_in *)cursor->ai_addr;
        printf("IP : %s  PORT : %d  FAMILY : %s\n", inet_ntoa(addr->sin_addr), addr->sin_port, addr->sin_family == AF_INET ? "AF_INET" : "AF_INET6");
    }

    freeaddrinfo(result);

    return 0;
}
