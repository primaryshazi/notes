#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>

#define MAX_MSG_LEN 1024

struct MsgInfo
{
    long msgType;
    char message[MAX_MSG_LEN];
};

int main(int argc, char const *argv[])
{
    key_t key = ftok("/root/.bashrc", 0);

    if (key < 0)
    {
        printf("ftok() error\n");
        exit(EXIT_FAILURE);
    }

    printf("key : %d\n", key);

    int msqid = msgget(key, IPC_CREAT | 0666);

    if (msqid < 0)
    {
        perror("msgget() error");
        exit(1);
    }

    printf("msqid is: %d\n", msqid);
    printf("pid is: %d\n", getpid());

    struct MsgInfo msgInfo;
    while (1)
    {
        msgInfo.msgType = 888;
        sprintf(msgInfo.message, "%ld", time(NULL));

        /**
         * __msgflg = 0 : 消息队列满时将会阻塞
         * __msgflg = IPC_NOWAIT : 消息队列满时立即返回错误
         */
        if (msgsnd(msqid, (void *)&msgInfo, MAX_MSG_LEN, 0) < 0)
        {
            printf("msgsnd() error\n");
            exit(EXIT_FAILURE);
        }

        memset(msgInfo.message, 0, MAX_MSG_LEN);

        sleep(1);
    }

    return 0;
}
