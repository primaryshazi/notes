#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define MAX_MSG_LEN 1024

void CreatFIFO(const char *fifoName)
{
    // 无进程打开则删除该文件
    unlink(fifoName);
    // 设置创建文件权限
    umask(0);
    if (mkfifo(fifoName, 0666) < 0)
    {
        printf("mkfifo() error\n");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char const *argv[])
{
    const char *fifoName = "/tmp/tempfifo";

    CreatFIFO(fifoName);

    /**
     * 阻塞读：阻塞到有相应进程以写打开命名管道
     * 非阻塞读：立即返回成功
     */
    int readFD = open(fifoName, O_RDONLY);

    if (readFD < 0)
    {
        printf("open() error\n");
        exit(EXIT_FAILURE);
    }

    char message[MAX_MSG_LEN] = "";

    while (1)
    {
        if (read(readFD, message, MAX_MSG_LEN - 1) < 0)
        {
            printf("read() error\n");
            exit(EXIT_FAILURE);
        }
        printf("Read : %s\n", message);
        if (atol(message) % 10 == 0)
        {
            printf("QUIT\n");
            break;
        }
        memset(message, 0, MAX_MSG_LEN);
    }

    close(readFD);
    sleep(1);
    unlink(fifoName);

    return 0;
}
