void swapValue(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int arr[], int low, int high)
{
    int standard = arr[high]; // 最后一个元素作为基准元素
    int index = low;          // 第一个不小于基准元素的索引

    // 将小于该基准元素的值移动至数组左边
    for (int i = low; i < high; ++i)
    {
        if (arr[i] < standard)
        {
            swapValue(arr + index, arr + i);
            ++index;
        }
    }
    // 将基准元素与第一个不小于基准元素交换
    swapValue(arr + high, arr + index);

    return index;
}

void qSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // 对数组进行部分排序，返回基准元素的索引
        int index = partition(arr, low, high);

        // 对小于和大于基准元素的部分进行递归部分排序
        qSort(arr, low, index - 1);
        qSort(arr, index + 1, high);
    }
}

void quickSort(int arr[], int N)
{
    qSort(arr, 0, N - 1);
}
