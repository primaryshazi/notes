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

    attr.mq_maxmsg = MAX_QUE_SIZE;    // 消息队列最大长度
    attr.mq_msgsize = MAX_MSG_LENGTH; // 每条消息最大长度
    attr.mq_flags = 0;                // 队列标志，0或O_NONBLOCK

    /**
     * => __name    消息队列名称
     * => __oflag   打开方法
     * => mode      读写权限
     * => attr      属性
     */
    int mqId = mq_open(msgQueName, O_CREAT | O_RDWR, msgQueMode, &attr);

    if (mqId < 0)
    {
        puts("mq_open() error");
        exit(EXIT_FAILURE);
    }

    for (;;)
    {
        unsigned int priority = 0; // 优先级
        char message[MAX_MSG_LENGTH] = "";

        /**
         * => __mqdes       消息队列ID
         * => __msg_ptr     储存消息数组
         * => __msg_len     获取消息最大长度
         * => __msg_prio    消息有限级
         */
        int length = mq_receive(mqId, message, MAX_MSG_LENGTH, &priority);

        if (length > 0)
        {
            printf("%s\n", message);

            if (strcmp("quit", message) == 0)
            {
                break;
            }
        }
        else if (length < 0)
        {
            puts("mq_receive() error");
            break;
        }
    }

    mq_close(mqId); // 关闭消息队列

    sleep(3);
    mq_unlink(msgQueName); // 删除消息队列

    return 0;
}
