#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void Finally()
{
    printf("process[%d] end\n", getpid());
}

int main(int argc, char const *argv[])
{
    /**
     * 进程正常结束前调用的函数
     */
    atexit(Finally);

    return 0;
}
