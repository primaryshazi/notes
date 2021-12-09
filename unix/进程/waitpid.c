#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

// 合理关闭子进程
void ChildProcess(int sig)
{
    int status = 0;

    /**
     * __pid：大于0则表示等待__pid进程结束，-1表示等待任何子进程结束，
     *        0表示等待当前进程组种任意进程结束，小于-1表示等待同一进程组种|__pid|结束
     * __options：WNOHANG表示非阻塞，
     */
    __pid_t pid = waitpid(-1, &status, WNOHANG);

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
    else if (0 == pid)  // 子进程
    {
        printf("child end\n");

        return 16;
    }
    else    // 父进程
    {
        printf("create child[%d]\n", pid);
        printf("father sleep 3s\n");
        sleep(3);
        printf("father end\n");
    }

    return 0;
}
