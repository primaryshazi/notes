#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char const *argv[])
{
    const char *baidu = "www.baidu.com";

    // 通过域名获取主机信息，仅适用于IPv4
    struct hostent *baiduHe = gethostbyname(baidu);

    /**
     * => www.a.shifen.com AF_INET
     * => aliases : www.baidu.com
     * => addr : 182.61.200.6
     * => addr : 182.61.200.7
     */
    printf("%s %s\n", baiduHe->h_name, baiduHe->h_addrtype == AF_INET ? "AF_INET" : "AF_INET6");

    for (int i = 0; NULL != baiduHe->h_aliases[i]; i++)
    {
        // 输出别名
        printf("aliases : %s\n", baiduHe->h_aliases[i]);
    }

    for (int i = 0; NULL != baiduHe->h_addr_list[i]; i++)
    {
        // 通过IP结构返回IP字符串
        printf("addr : %s\n", inet_ntoa(*(struct in_addr *)baiduHe->h_addr_list[i]));
    }

    return 0;
}
