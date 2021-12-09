#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

// 合理关闭子进程
void ChildProcess(int sig)
{
    int status = 0;

    // 阻塞等待任意进程结束
    __pid_t pid = wait(&status);

    // 判断子进程关闭是否成功
    if (WIFEXITED(status))
    {
        // 子进程的返回值
        printf("child[%d] return : %d\n", pid, WEXITSTATUS(status));
    }
    else
    {
        printf("child[%d] exception\n", pid);
    }
}

int main(int argc, char const *argv[])
{
    // 注册子进程处理
    signal(SIGCHLD, ChildProcess);

    __pid_t pid = fork();

    if (pid < 0)
    {
        printf("fork() error\n");
    }
    else if (0 == pid) // 子进程
    {
        printf("child end\n");

        return 16;
    }
    else // 父进程
    {
        printf("create child[%d]\n", pid);
        printf("father sleep 3s\n");
        sleep(3);
        printf("father end\n");
    }

    return 0;
}
