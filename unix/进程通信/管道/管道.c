#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>

#define MAX_MSG_LEN 1024

int main(int argc, char const *argv[])
{
    int fd[2] = {0};
    __pid_t pid;

    if (pipe(fd) < 0)
    {
        printf("pipe() error\n");
        exit(EXIT_FAILURE);
    }

    /**
     * 只适用于有亲缘关系的进程
     * fd[0]通道读，fd[1]通道写
     * 从父到子，父关闭读，子关闭写
     * 从子到父，子关闭读，父关闭写
     */
    if ((pid = fork()) < 0)
    {
        printf("fork() error\n");
        exit(EXIT_FAILURE);
    }
    else if (pid > 0)
    {
        close(fd[0]);
        char message[MAX_MSG_LEN] = "Hello World!\n";
        write(fd[1], message, strlen(message));
        wait(NULL);
    }
    else
    {
        close(fd[1]);
        char message[MAX_MSG_LEN] = "";
        int length = read(fd[0], message, MAX_MSG_LEN - 1);

        /**
         * => Hello World!
         */
        write(STDOUT_FILENO, message, length);
    }

    return 0;
}
