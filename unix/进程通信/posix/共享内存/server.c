#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

#define LOOP_SIZE 100
#define BUFFER_SIZE 4

int main(int argc, char const *argv[])
{
    const char *shmName = "/tempshm";
    const char *semName = "/tempsem";

    // 创建共享内存句柄
    int fd = shm_open(shmName, O_RDWR | O_CREAT, 0666);

    if (fd < 0)
    {
        puts("open() error");
        exit(EXIT_FAILURE);
    }
    // 将共享内存阶截断为BUFFER_SIZE长度
    ftruncate(fd, BUFFER_SIZE);

    sem_t *sem = sem_open(semName, O_CREAT, 0666, 1);

    if (NULL == sem)
    {
        puts("sem_open() error");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < LOOP_SIZE; i++)
    {
        char buffer[BUFFER_SIZE] = "";

        sem_wait(sem);

        read(fd, buffer, BUFFER_SIZE);
        printf("[server] %s\n", buffer);

        sem_post(sem);
    }

    sem_close(sem);
    sem_unlink(semName);
    shm_unlink(shmName);

    return 0;
}
