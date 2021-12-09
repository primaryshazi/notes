/**
 * 水平触发：接受一次数据则注册一次事件
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <errno.h>
#include <fcntl.h>

#define BUF_SIZE 256
#define EPOLL_SIZE 50

int main(int argc, char const *argv[])
{
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

    // 创建EPOLL_SIZE个监听集合
    int epollFd = epoll_create(EPOLL_SIZE);

    if (epollFd < 0)
    {
        puts("epoll_create() error");
        exit(EXIT_FAILURE);
    }

    struct epoll_event *epollEvents = calloc(EPOLL_SIZE, sizeof(struct epoll_event));

    if (NULL == epollEvents)
    {
        puts("calloc() error");
        exit(EXIT_FAILURE);
    }

    struct epoll_event event;

    memset(&event, 0, sizeof(event));

    /**
     * EPOLLIN      读数据
     * EPOLLOUT     写数据
     * EPOLLPRI     紧急数据
     * EPOLLRDHUP   断开连接或半连接
     * EPOLLERR     发生错误
     * EPOLLET      边缘触发
     * EPOLLONESHOT 只接收一次数据
     */
    event.events = EPOLLIN;
    event.data.fd = serverSock;

    /**
     * 将服务端添加到监听中
     *
     * __epfd       epoll描述符
     * __op         操作选项
     * __fd         要操作的描述符
     * __event      监听事件集
     *
     * EPOLL_CTL_ADD    添加描述符
     * EPOLL_CTL_DEL    删除描述符
     * EPOLL_CTL_MOD    修改描述符
     */
    if (epoll_ctl(epollFd, EPOLL_CTL_ADD, serverSock, &event) < 0)
    {
        puts("epoll_ctl() error");
        exit(EXIT_FAILURE);
    }

    for (;;)
    {
        /**
         * @brief
         *
         */
        int clientEvent = epoll_wait(epollFd, epollEvents, EPOLL_SIZE, -1); // 等待事件的发生
        if (clientEvent < 0)
        {
            puts("epoll_wait() error");
            break;
        }

        for (int i = 0; i < clientEvent; i++)
        {
            int activeEventFd = epollEvents[i].data.fd;

            /**
             * 服务端事件则向监听中添加连接的客户端套接字
             * 客户端时间则接受数据并回复
             */
            if (activeEventFd == serverSock)
            {
                int clientSock = 0;
                struct sockaddr_in clientAddr;
                socklen_t addrLength = sizeof(clientAddr);

                clientSock = accept(serverSock, (struct sockaddr *)&clientAddr, &addrLength);

                event.events = EPOLLIN; // 设置为水平触发
                event.data.fd = clientSock;

                epoll_ctl(epollFd, EPOLL_CTL_ADD, clientSock, &event); // 从监听中增加该套接字

                printf("connected client : %d\n", clientSock);
            }
            else
            {
                char buf[BUF_SIZE] = "\0";
                int length = read(activeEventFd, buf, BUF_SIZE - 1);

                if (length > 0)
                {
                    write(activeEventFd, buf, length);
                    printf("[client %d] : %s\n", activeEventFd, buf);
                }
                else
                {
                    epoll_ctl(epollFd, EPOLL_CTL_DEL, activeEventFd, NULL); // 从监听中删除该套接字
                    close(activeEventFd);
                    printf("closed client : %d\n", activeEventFd);
                }
            }
        }
    }
    close(serverSock);
    close(epollFd);
    free(epollEvents);

    return 0;
}
