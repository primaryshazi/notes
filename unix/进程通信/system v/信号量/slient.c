#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <unistd.h>
#include <time.h>

union Semun
{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

int SetP(const int semid)
{
    struct sembuf sembf = {
        .sem_num = 0,
        .sem_op = -1,
        .sem_flg = SEM_UNDO};

    return semop(semid, &sembf, 1);
}

int SetV(const int semid)
{
    struct sembuf sembf = {
        .sem_num = 0,
        .sem_op = 1,
        .sem_flg = SEM_UNDO};

    return semop(semid, &sembf, 1);
}

int main(int argc, char *argv[])
{
    key_t key = ftok("/root/.bashrc", 10);

    if (key < 0)
    {
        printf("ftok() error\n");
        exit(EXIT_FAILURE);
    }

    //创建信号量
    int semid = semget(key, 1, IPC_CREAT | 0666);

    if (semid < 0)
    {
        printf("semget() error");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        if (SetP(semid) < 0)
        {
            printf("SetP() error");
            exit(EXIT_FAILURE);
        }

        sleep(1);

        if (SetV(semid) < 0)
        {
            printf("SetV() error\n");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
