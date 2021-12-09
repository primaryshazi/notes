#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>

#define MAX_MSG_LEN 1024

/**
 * 消息队列信息结构体
 */
struct MsgInfo
{
    long msgType;
    char message[MAX_MSG_LEN];
};

int main(int argc, char const *argv[])
{
    /**
     * 依据路径名及ID返回键值
     * ID范围[0, 255]
     */
    key_t key = ftok("/root/.bashrc", 0);

    if (key < 0)
    {
        printf("ftok() error\n");
        exit(EXIT_FAILURE);
    }

    printf("key : %d\n", key);

    /**
     * IPC_CREAT: 如果不存在key值的消息队列，且权限不为0，则创建消息队列，并返回一个消息队列ID。如果存在，则直接返回消息队列ID
     * IPC_CREAT | IPC_EXCL: 如果不存在key值的消息队列，且权限不为0，则创建消息队列，并返回一个消息队列ID。如果存在，则产生错误
     */
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
        /**
         * __msgtyp = 0 : 返回队列中第一个消息
         * __msgtyp > 0 : 返回队列中第一个消息类型为__msgtyp的消息
         * __msgtyp < 0 : 返回消息类型小于等于__msgtyp中最小的消息
         * 
         * __msgflg = 0 : 阻塞等待消息
         * __msgflg = IPC_NOWAIT : 没有符合条件的消息立刻返回
         * __msgflg = IPC_EXCEPT : 返回第一个不符合条件的消息
         */
        if (msgrcv(msqid, (void *)&msgInfo, MAX_MSG_LEN, 888, 0) < 0)
        {
            printf("msgrcv() error\n");
            break;
        }
        printf("Type[%ld] Message[%s]\n", msgInfo.msgType, msgInfo.message);

        if (atol(msgInfo.message) % 10 == 0)
        {
            printf("QUIT\n");
            break;
        }
    }

    /**
     * __cmd = IPC_RMID : 删除消息队列
     * __cmd = IPC_STAT : 取出该消息队列中的消息放在__buf之中
     * __cmd = IPC_SET : 改变消息队列状态为__buf参数中的状态
     */
    if (msgctl(msqid, IPC_RMID, NULL) < 0)
    {
        printf("msgctl() error\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}
