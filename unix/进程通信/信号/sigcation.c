#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define __USE_POSIX

#include <signal.h>

void ChildMsg()
{
    printf("[%d] you can't kill me\n", getpid());
}

int main()
{
    struct sigaction act;
    struct sigaction oact;

    // 注册信号处理函数
    act.sa_handler = ChildMsg;
    // 清空信号屏蔽
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;

    __pid_t pid = 0;

    // 设置针对于SIGKILL信号的新的屏蔽方式act，获取默认信号处理方式于oact
    sigaction(SIGINT, &act, &oact);

    pid = fork();

    if (pid < 0)
    {
        printf("fork() error\n");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        while (1)
        {
            printf("I'm [%d]\n", getpid());
            sleep(1);
        }
    }
    else
    {
        // 父进程恢复原有的屏蔽方式
        sigaction(SIGINT, &oact, NULL);
        for (int i = 0; i < 5; i++)
        {
            sleep(2);
            printf("kill -2 [%d]\n", pid);
            kill(pid, SIGINT);
        }
        printf("kill -9 [%d]\n", pid);
        kill(pid, SIGKILL);
    }

    return 0;
}
