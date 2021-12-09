#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define MAX_MSG_LEN 1024

int main(int argc, char const *argv[])
{
    const char *fifo = "/tmp/tempfifo";

    /**
     * 阻塞写：阻塞到有相应进程以读打开命名管道
     * 非阻塞写：立刻返回失败
     */
    int writeFD = open(fifo, O_WRONLY);

    if (writeFD < 0)
    {
        printf("open() error\n");
        exit(EXIT_FAILURE);
    }

    char message[MAX_MSG_LEN] = "";

    while (1)
    {
        sprintf(message, "%ld", time(NULL));
        if (write(writeFD, message, strlen(message)) < 0)
        {
            printf("write() error\n");
            exit(EXIT_FAILURE);
        }
        memset(message, 0, MAX_MSG_LEN);
        sleep(1);
    }

    close(writeFD);

    return 0;
}
