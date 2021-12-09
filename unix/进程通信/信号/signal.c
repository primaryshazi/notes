#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define __USE_POSIX

#include <signal.h>

void ChildMsg()
{
    printf("[%d] you can't kill me\n", getpid());
    signal(SIGINT, ChildMsg);
}

int main()
{
    __pid_t pid = fork();

    if (pid < 0)
    {
        printf("fork() error\n");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        signal(SIGINT, ChildMsg);

        while (1)
        {
            printf("I'm [%d]\n", getpid());
            sleep(1);
        }
    }
    else
    {
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
