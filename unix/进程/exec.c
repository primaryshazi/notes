#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

// 环境变量，NULL表示环境变量结尾
char *environment[] = {"PATH=/usr/local/bin:/usr/bin:/root/bin", NULL};
char *argument[] = {"-s", NULL};

void Func(int mode)
{
    switch (mode)
    {
    case 0:
        execl("/usr/bin/uname", "uname", "-s", NULL);
        break;
    case 1:
        execlp("uname", "uname", "-s", NULL);
        break;
    case 2:
        execle("/usr/bin/uname", "uname", "-s", NULL, environment);
        break;
    case 3:
        execv("/usr/bin/uname", argument);
        break;
    case 4:
        execvp("uname", argument);
        break;
    case 5:
        execve("/usr/bin/uname", argument, environment);
        break;
    default:
        printf("error\n");
        break;
    }
    printf("errno[%d] %s\n", errno, strerror(errno));
}

int main(int argc, char const *argv[])
{
    Func(5);

    return 0;
}
