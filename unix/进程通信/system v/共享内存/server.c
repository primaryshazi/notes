#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <errno.h>

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
        printf("%d %s\n", errno, strerror(errno));
        printf("shmget() error\n");
        exit(EXIT_FAILURE);
    }

    printf("shmid : %d\n", shmid);

    while (1)
    {
        /**
         * 返回共享内存的地址
         * __shmaddr：NULL表示让系统选择可用的位置，非空则读写指定位置，若指定了SHM_RND则取整
         * __shmflg：SHM_RDONLY表示只读模式，其余为读写模式
         */
        char *pShm = shmat(shmid, NULL, 0);

        long now = atoi(pShm);

        printf("%d\n", now);

        /**
         * 将共享内存从当前进程中分离
         */
        if (shmdt(pShm) < 0)
        {
            printf("shmdt() error");
            exit(EXIT_FAILURE);
        }

        if (now % 100 == 0 && now != 0)
        {
            printf("QUIT\n");
            break;
        }

        sleep(1);
    }

    sleep(1);
    if (shmctl(shmid, IPC_RMID, NULL) < 0)
    {
        printf("shmctl() error\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}
