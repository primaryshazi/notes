#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>

int main(int argc, char const *argv[])
{
    /**
     * family   PF_INET（IPv4协议）；PF_INET6（IPv6协议）；PF_LOCAL（UNIX域协议）；
     *          PF_ROUTE（路由套接字协议）；PF_KEY（密钥套接字）
     * type     SOCK_STREAM（字节流套接字）；SOCKET_DGRAM（数据报套接字）；
     *          SOCK_SEQPACKET（有序分组套接字）；SOCK_RAW（原始套接字）
     * protocol IPPROTO_TCP（TCP协议）；IPPROTO_UDP（UDP协议）；IPPROTO_SCTP（SCTP协议）
     */
    int tcpSock = socket(PF_INET, SOCK_STREAM, 0); // 打开TCP套接字
    int udpSock = socket(PF_INET, SOCK_DGRAM, 0);  // 打开UDP套接字

    /**
     * => tcp : 5
     * => tcp : 6
     */
    printf("tcp : %d\n", tcpSock);
    printf("udp : %d\n", udpSock);

    // 描述符的引用计数减一，减至零则关闭
    close(tcpSock); // 关闭TCP套接字
    close(udpSock); // 关闭UDP套接字

    return 0;
}
