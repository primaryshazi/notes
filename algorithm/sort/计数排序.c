#include <stdlib.h>

int findMax(int arr[], const int N)
{
    int max = 0;

    for (int i = 0; i < N; ++i)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}

void countSort(int arr[], const int N)
{
    // 找到数组中最大的值，创建一个容量为size + 1的数组
    int size = findMax(arr, N) + 1;
    int *tempArr = (int *)calloc(size, sizeof(int));

    // 将arr中每个数的个数储存到temparr
    for (int i = 0; i < N; ++i)
    {
        ++tempArr[arr[i]];
    }

    // 如果tempArr[i] > 0，则将tempArr[i]个i拷贝到arr中
    for (int i = 0, k = 0; i < size; ++i)
    {
        for (int j = 0; j < tempArr[i]; ++j, ++k)
        {
            arr[k] = i;
        }
    }

    free(tempArr);
    tempArr = NULL;
}
