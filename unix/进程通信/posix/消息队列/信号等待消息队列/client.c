#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <mqueue.h>

#define MAX_QUE_SIZE 64
#define MAX_MSG_LENGTH 1024

int main(int argc, char const *argv[])
{
    const char *msgQueName = "/msgqueue";
    int msgQueMode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;
    struct mq_attr attr;
    __bzero(&attr, sizeof(attr));

    attr.mq_maxmsg = MAX_QUE_SIZE;
    attr.mq_msgsize = MAX_MSG_LENGTH;
    attr.mq_flags = 0;

    int mqId = mq_open(msgQueName, O_CREAT | O_RDWR, msgQueMode, &attr);

    if (mqId < 0)
    {
        puts("mq_open() error");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 10; i++)
    {
        unsigned int priority = 0; // 优先级
        char message[MAX_MSG_LENGTH] = "";
        scanf("%s", message);

        if (mq_send(mqId, message, strlen(message), priority) < 0)
        {
            puts("mq_send() error");
            break;
        }
        if (strcmp("quit", message) == 0)
        {
            break;
        }
    }

    mq_close(mqId);

    return 0;
}
