#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <limits.h>
#include <poll.h>

#define BUF_SIZE 256

int main(int argc, char const *argv[])
{
    int serverSock = socket(PF_INET, SOCK_STREAM, 0);
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

    const int c_openMax = sysconf(_SC_OPEN_MAX);
    struct pollfd monitorPoll[c_openMax];
    int maxIndex = 0; // monitorPoll最大索引

    /**
     * POLLIN           有数据可读
     * POLLRDNORM       有普通数据可读
     * POLLRDBAND       有优先数据可读
     * POLLPRI          有紧急数据可读
     * POLLOUT          数据可写
     * POLLWRNORM       普通数据可写
     * POLLWRBAND       优先数据可写
     * POLLMSGSIGPOLL   消息可用
     * POLLERR          指定描述符发生错误
     * POLLHUP          指定文件描述符挂起事件
     * POLLNVAL         指定描述符非法
     */
    monitorPoll[0].fd = serverSock;
    monitorPoll[0].events = POLLIN;

    for (int i = 1; i < c_openMax; i++)
    {
        monitorPoll[i].fd = -1;
    }

    for (;;)
    {
        // 返回就绪描述符数量
        int readyNum = poll(monitorPoll, maxIndex + 1, -1);

        int clientSock = 0;
        struct sockaddr_in clientAddr;
        socklen_t addrLength = sizeof(clientAddr);

        for (int i = 0; i < maxIndex + 1; i++)
        {
            if ((clientSock = monitorPoll[i].fd) < 0)
            {
                continue;
            }

            if (monitorPoll[i].revents & (POLLIN | POLLERR))
            {
                /**
                 * 服务端出现事则激活连接的客户端套接字
                 * 客户端有事件读取客户端发送的信息并回复
                 */
                if (0 == i)
                {
                    memset(&clientAddr, 0, sizeof(clientAddr));
                    clientSock = accept(serverSock, (struct sockaddr *)&clientAddr, &addrLength);

                    // 找到第一个为未使用的位置的索引
                    int index = 1;
                    while (monitorPoll[index].fd >= 0)
                    {
                        index++;

                        // 索引等于最大值则直接退出
                        if (index == c_openMax)
                        {
                            printf("client too many\n");
                            exit(EXIT_FAILURE);
                        }
                    }

                    // 为新连接的描述符指定监视事件
                    monitorPoll[index].fd = clientSock;
                    monitorPoll[index].events = POLLIN;

                    if (maxIndex < index)
                    {
                        maxIndex = index;
                    }

                    printf("connect client : %d\n", clientSock);
                }
                else
                {
                    char message[BUF_SIZE] = "\0";
                    int length = read(clientSock, message, BUF_SIZE - 1);

                    if (length > 0)
                    {
                        write(clientSock, message, length);
                        printf("[client %d] : %s\n", clientSock, message);
                    }
                    else
                    {
                        close(clientSock);
                        monitorPoll[i].fd = -1;
                        printf("closed client : %d\n", clientSock);
                    }
                }

                // 就绪数量处理完则退出循环
                if (--readyNum <= 0)
                {
                    break;
                }
            }
        }
    }
    close(serverSock);

    return 0;
}
