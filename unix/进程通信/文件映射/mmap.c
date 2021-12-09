#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

#define LOOP_SIZE 5

int main(int argc, char const *argv[])
{
    const char *filename = "tempfile";
    const char *semName = "/tempsem";

    int fd = open(filename, O_RDWR | O_CREAT, 0666);

    if (fd < 0)
    {
        puts("open() error");
        exit(EXIT_FAILURE);
    }

    // 提前写入字符
    int value = 0;
    write(fd, &value, sizeof(int));

    /**
     * 将fd的文件映射到ptr执行的一块内存上，长度为sizeof(int)
     *
     * => __addr        映射内存地址，NULL则由内核自动分配
     * => __len         映射内存长度
     * => __prot
     * => __flags
     * => __fd
     * => __offset
     */
    int *ptr = (int *)mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    if (NULL == ptr)
    {
        puts("mmap() error");
        exit(EXIT_FAILURE);
    }

    sem_unlink(semName);
    sem_t *sem = sem_open(semName, O_CREAT, 0666, 1);

    if (NULL == sem)
    {
        puts("mmap() error");
        exit(EXIT_FAILURE);
    }

    int pid = fork();

    /**
     * => father : 0
     * => father : 1
     * => father : 2
     * => father : 3
     * => father : 4
     * => child : 5
     * => child : 6
     * => child : 7
     * => child : 8
     * => child : 9
     */
    if (0 == pid)
    {
        for (int i = 0; i < LOOP_SIZE; i++)
        {
            sem_wait(sem);
            printf("child : %d\n", (*ptr)++);
            sem_post(sem);
        }

        return 0;
    }
    else if (pid > 0)
    {
        for (int i = 0; i < LOOP_SIZE; i++)
        {
            sem_wait(sem);
            printf("father : %d\n", (*ptr)++);
            sem_post(sem);
        }
    }
    else
    {
        puts("fork() error");
        exit(EXIT_FAILURE);
    }

    sleep(1);
    close(fd);
    sem_close(sem);
    sem_unlink(semName);

    // 删除内存映射
    munmap(ptr, sizeof(int));

    return 0;
}
