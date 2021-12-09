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

int Init(const int semid)
{
    union Semun semun = {.val = 1};

    /**
     * 设置位置为0的信号量的初始值为1
     */
    return semctl(semid, 0, SETVAL, semun);
}

int SetP(const int semid)
{
    struct sembuf sembf = {
        .sem_num = 0,
        .sem_op = -1,
        .sem_flg = SEM_UNDO};

    /**
     * 阻塞等待获取该0号信号量，并加上sem_op的绝对值
     */
    return semop(semid, &sembf, 1);
}

int SetV(const int semid)
{
    struct sembuf sembf = {
        .sem_num = 0,
        .sem_op = 1,
        .sem_flg = SEM_UNDO};

    /**
     * 释放0号信号量，并减去sem_op
     */
    return semop(semid, &sembf, 1);
}

int Delete(const int semid)
{
    union Semun semun;

    /**
     * 删除0号信号量
     */
    return semctl(semid, 0, IPC_RMID, semun);
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

    if (Init(semid) < 0)
    {
        printf("Init() error\n");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        if (SetP(semid) < 0)
        {
            printf("SetP() error");
            exit(EXIT_FAILURE);
        }
        time_t now = time(NULL);

        printf("%ld\n", now);

        if (SetV(semid) < 0)
        {
            printf("SetV() error\n");
            exit(EXIT_FAILURE);
        }

        if (now % 100 == 0)
        {
            printf("QUIT\n");
            break;
        }
    }

    if (Delete(semid) < 0)
    {
        printf("Delete() error\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}
