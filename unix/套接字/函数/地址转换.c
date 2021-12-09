#include <stdio.h>
#include <stdlib.h>

#define __USE_MISC

#include <arpa/inet.h>

int main(int argc, char const *argv[])
{
    const char *ip = "127.0.0.1";
    uint16_t port = 8080;

    struct in_addr oldAddr;
    const char *oldSZ = NULL;

    // 支持IPv4
    inet_addr(ip);              // IP字符符串获取IP数值
    inet_aton(ip, &oldAddr);    // IP字符符串获取IP结构
    oldSZ = inet_ntoa(oldAddr); // IP结构获取IP字符串

    /**
     * => newAddr.s_addr  : 16777343
     * => oldSZ           : 127.0.0.1
     */
    printf("newAddr.s_addr  : %u\n", oldAddr.s_addr);
    printf("oldSZ           : %s\n", oldSZ);

    struct in_addr newAddr;
    char newSZ[64] = "";

    // 支持IPv4，IPv6
    inet_pton(AF_INET, ip, &newAddr.s_addr);                     // IP字符符串获取IP结构
    inet_ntop(AF_INET, &newAddr.s_addr, newSZ, INET_ADDRSTRLEN); // IP结构获取IP字符串

    /**
     * => newAddr.s_addr  : 16777343
     * => newSZ           : 127.0.0.1
     */
    printf("newSZ.s_addr    : %u\n", newAddr.s_addr);
    printf("newSZ           : %s\n", newSZ);

    /**
     * => 2417950720
     * => 36895
     * => 2417950720
     * => 36895
     */
    printf("%u\n", ntohl(port)); // 无符号长整形转换为网路字节序
    printf("%d\n", ntohs(port)); // 无符号短整形转换为网路字节序
    printf("%u\n", htonl(port)); // 无符号长整形转换为主机字节序
    printf("%d\n", htons(port)); // 无符号短整形转换为主机字节序

    return 0;
}
