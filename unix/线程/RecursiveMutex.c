#include <stdio.h>
#include <stdlib.h>

#define __USE_XOPEN2K
#include <pthread.h>

pthread_mutex_t g_mutex = PTHREAD_MUTEX_INITIALIZER;

void *Func(void *arg)
{
    pthread_mutex_lock(&g_mutex);

    int value = (*((int *)arg))--;
    if (value > 0)
    {
        printf("%d\n", value);
        Func(arg);
    }

    pthread_mutex_unlock(&g_mutex);

    return NULL;
}

int main(int argc, char const *argv[])
{
    pthread_mutexattr_t mtxAttr;
    pthread_mutexattr_init(&mtxAttr);
    pthread_mutexattr_settype(&mtxAttr, PTHREAD_MUTEX_RECURSIVE_NP);
    pthread_mutex_init(&g_mutex, &mtxAttr); // 设置递归属性

    pthread_t ptd = 0;
    int value = 10;

    if (pthread_create(&ptd, NULL, Func, (void *)&value) != 0)
    {
        printf("thread 1 create fail\n");
        exit(EXIT_FAILURE);
    }

    pthread_join(ptd, NULL);
    pthread_mutex_destroy(&g_mutex);
    pthread_mutexattr_destroy(&mtxAttr);

    return 0;
}
