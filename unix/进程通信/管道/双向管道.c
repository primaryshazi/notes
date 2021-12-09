#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>

#define MAX_MSG_LEN 1024

int main(int argc, char const *argv[])
{
    int fd_fs[2] = {0};     // 父到子管道
    int fd_sf[2] = {0};     // 子到父管道
    __pid_t pid;

    if (pipe(fd_fs) < 0 || pipe(fd_sf) < 0)
    {
        printf("pipe() error\n");
        exit(EXIT_FAILURE);
    }

    /**
     * => Children read : Hello World!
     * => Father read: Hello World!
     */
    if ((pid = fork()) < 0)
    {
        printf("fork() error\n");
        exit(EXIT_FAILURE);
    }
    else if (pid > 0)
    {
        close(fd_fs[0]);
        close(fd_sf[1]);

        char message[MAX_MSG_LEN] = "Hello World!";

        write(fd_fs[1], message, strlen(message));
        memset(message, 0, MAX_MSG_LEN);

        read(fd_sf[0], message, MAX_MSG_LEN - 1);

        printf("Father read : %s\n", message);
        wait(NULL);
    }
    else
    {
        close(fd_fs[1]);
        close(fd_sf[0]);

        char message[MAX_MSG_LEN] = "";

        read(fd_fs[0], message, MAX_MSG_LEN - 1);
        printf("Children read : %s\n", message);
        write(fd_sf[1], message, strlen(message));
    }

    return 0;
}
