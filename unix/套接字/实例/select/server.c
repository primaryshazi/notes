#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/select.h>

#define BUF_SIZE 256

int main(int argc, char const *argv[])
{
    fd_set sockReads;     // 注册的socket
    fd_set copySockReads; // 拷贝注册的socket
    struct timeval timeout;

    int serverSock = socket(PF_INET, SOCK_STREAM, 0);

    int option = 1;
    if (setsockopt(serverSock, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option)) < 0)
    {
        puts("setsockopt() error");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in serverAddr;

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (bind(serverSock, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
    {
        puts("bind() error");
        exit(EXIT_FAILURE);
    }

    if (listen(serverSock, 5) < 0)
    {
        puts("listen() error");
        exit(EXIT_SUCCESS);
    }

    FD_ZERO(&sockReads);            // 初始清空注册集
    FD_SET(serverSock, &sockReads); // 将serverSock添加到注册集
    int fdMax = serverSock;         // 记录当前最大描述符

    for (;;)
    {
        copySockReads = sockReads; // 备份当前注册集

        // 赋予超时时间为3秒
        timeout.tv_sec = 3;
        timeout.tv_usec = 0;

        /**
         * 返回0超时，返回小于零则错误，大于零表示就绪描述符
         */
        int fdNum = select(fdMax + 1, &copySockReads, 0, 0, &timeout);
        if (fdNum < 0)
        {
            puts("select() error");
            break;
        }
        if (0 == fdNum)
        {
            printf("timeout...\n");
            continue;
        }

        // 遍历注册集
        for (int i = 0; i < fdMax + 1; i++)
        {
            // 处理已注册集
            if (FD_ISSET(i, &copySockReads) > 0)
            {
                int clientSock = 0;
                struct sockaddr_in clientAddr;
                socklen_t addrLength = sizeof(clientAddr);

                /**
                 * 服务端有事件则注册请求连接的客户端
                 * 客户端有事件读取客户端发送的信息并回复
                 */
                if (i == serverSock)
                {
                    memset(&clientAddr, 0, sizeof(clientAddr));
                    clientSock = accept(serverSock, (struct sockaddr *)&clientAddr, &addrLength);
                    FD_SET(clientSock, &sockReads);

                    if (fdMax < clientSock)
                    {
                        fdMax = clientSock;
                    }
                    printf("connect client : %d\n", clientSock);
                }
                else
                {
                    clientSock = i;

                    char message[BUF_SIZE] = "\0";
                    int length = read(clientSock, message, BUF_SIZE - 1);

                    // 客户端有信息发送则回复，无信息则关闭该套接字，并从注册集中删除
                    if (length > 0)
                    {
                        write(clientSock, message, length);
                        printf("[client %d] : %s\n", clientSock, message);
                    }
                    else
                    {
                        FD_CLR(clientSock, &sockReads);
                        close(clientSock);
                        printf("closed client : %d\n", clientSock);
                    }
                }
            }
        }
    }
    close(serverSock);

    return 0;
}
