#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <time.h>

#define MAX_MSG_LEN 1024
#define MAX_SHM_SIZE 1024

int main(int argc, char const *argv[])
{
    int key = ftok("/root/.bashrc", 20);

    if (key < 0)
    {
        printf("ftok() error\n");
        exit(EXIT_FAILURE);
    }

    printf("key : %d\n", key);

    int shmid = shmget(key, MAX_SHM_SIZE, IPC_CREAT | 0666);

    if (shmid < 0)
    {
        printf("shmget() error\n");
        exit(EXIT_FAILURE);
    }

    printf("shmid : %d\n", shmid);

    while (1)
    {
        char *pShm = shmat(shmid, NULL, 0);

        long now = time(NULL);
        memset(pShm, 0, MAX_SHM_SIZE);
        sprintf(pShm, "%d", now);

        if (shmdt(pShm) < 0)
        {
            printf("shmdt() error");
            exit(EXIT_FAILURE);
        }

        if (now % 100 == 0)
        {
            break;
        }

        sleep(1);
    }

    return 0;
}
