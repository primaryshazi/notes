#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char const *argv[])
{
    struct in_addr addr;
    memset(&addr, 0, sizeof(addr));

    const char *ip = "127.0.0.1";

    inet_pton(AF_INET, ip, &addr);

    // 通过IP结构获取主机信息，仅适用于IPv4
    struct hostent *he = gethostbyaddr((void *)&addr, sizeof(struct in_addr), AF_INET);

    /**
     * => localhost AF_INET
     * => aliases : localhost.localdomain
     * => aliases : localhost4
     * => aliases : localhost4.localdomain4
     * => addr : 127.0.0.1
     */
    printf("%s %s\n", he->h_name, he->h_addrtype == AF_INET ? "AF_INET" : "AF_INET6");

    for (int i = 0; NULL != he->h_aliases[i]; i++)
    {
        // 输出别名
        printf("aliases : %s\n", he->h_aliases[i]);
    }

    for (int i = 0; NULL != he->h_addr_list[i]; i++)
    {
        // 通过IP结构返回IP字符串
        printf("addr : %s\n", inet_ntoa(*(struct in_addr *)he->h_addr_list[i]));
    }

    return 0;
}
