#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define __USE_POSIX

#include <netdb.h>
#include <arpa/inet.h>

#define MAX_LENGTH 1024

int main(int argc, char const *argv[])
{
    const char *ip = "www.baidu.com";
    struct addrinfo hints;          // 期望选项
    struct addrinfo *result = NULL; // 返回结果

    memset(&hints, 0, sizeof(hints));

    hints.ai_family = AF_INET;       // IPv4协议族
    hints.ai_protocol = 0;           // 任何协议
    hints.ai_socktype = SOCK_STREAM; // 数据流

    if (getaddrinfo(ip, NULL, &hints, &result) < 0)
    {
        puts("getaddrinfo() error");
        exit(EXIT_FAILURE);
    }

    /**
     * => 182.61.200.6  0
     * => 182.61.200.7  0
     */
    for (struct addrinfo *cursor = result; cursor != NULL; cursor = cursor->ai_next)
    {
        char host[MAX_LENGTH] = "";
        char server[MAX_LENGTH] = "";
        getnameinfo(cursor->ai_addr, cursor->ai_addrlen, host, MAX_LENGTH, server, MAX_LENGTH, NI_NUMERICHOST);

        printf("%s  %s\n", host, server);
    }

    freeaddrinfo(result);

    return 0;
}
