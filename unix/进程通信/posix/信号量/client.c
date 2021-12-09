#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char const *argv[])
{
    const char *semName = "/tmpsem";
    sem_t *sem = NULL;

    if ((sem = sem_open(semName, 0)) == NULL)
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

        sleep(1);

        if (sem_post(sem) < 0)
        {
            printf("sem_post() error\n");
            exit(EXIT_FAILURE);
        }
    }

    if (sem_close(sem) < 0)
    {
        printf("sem_close() error\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}
