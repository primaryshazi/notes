#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <time.h>
#include <sys/stat.h>

int main(int argc, char const *argv[])
{
    const char *semName = "/tmpsem";
    sem_t *sem = NULL;

    sem_unlink(semName);

    /**
     * => 信号名
     * => 打开模式
     * => 权限
     * => 初始值
     */
    if ((sem = sem_open(semName, O_CREAT, 0666, 1)) == NULL)
    {
        printf("sem_open() error\n");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        if (sem_wait(sem) < 0)
        {
            printf("sem_wait() error\n");
            exit(EXIT_FAILURE);
        }

        time_t now = time(NULL);

        printf("%ld\n", now);

        if (sem_post(sem) < 0)
        {
            printf("sem_post() error\n");
            exit(EXIT_FAILURE);
        }

        if (now % 100 == 0)
        {
            printf("QUIT\n");
            break;
        }
    }

    if (sem_close(sem) < 0)
    {
        printf("sem_close() error\n");
        exit(EXIT_FAILURE);
    }
    sleep(1);
    if (sem_unlink(semName) < 0)
    {
        printf("sem_close() error\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}
