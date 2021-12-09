#include <stdlib.h>

void merge(int arr[], int left, int mid, int right)
{
    int leftLen = mid - left + 1; // 获取左数组的长度
    int rightLen = right - mid;   // 获取右数组的长度

    int *leftArr = (int *)calloc(leftLen, sizeof(int));
    int *rightArr = (int *)calloc(leftLen, sizeof(int));

    // 复制左右区间元素
    for (int i = 0; i < leftLen; ++i)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < rightLen; ++i)
        rightArr[i] = arr[mid + 1 + i];

    int lIndex = 0;
    int rIndex = 0;
    int index = left;

    // 将顺序左右数组进行按序归并
    while (lIndex < leftLen || rIndex < rightLen)
    {
        /**
         * 将较小的数存入数组左边，较大的数存入数据右边
         * 当右数组已经遍历完毕，或者左数组没有遍历完毕且左数组当前数小于右数组当前数则将数据存入数组左边，否则存入右边
         */
        if (rIndex >= rightLen || (lIndex < leftLen && leftArr[lIndex] <= rightArr[rIndex]))
        {
            arr[index] = leftArr[lIndex];
            ++lIndex;
        }
        else
        {
            arr[index] = rightArr[rIndex];
            ++rIndex;
        }
        ++index;
    }
    free(leftArr);
    free(rightArr);
}

void mSort(int arr[], int left, int right)
{
    // 对左右元素进行递归处理
    if (left < right)
    {
        // 将左右分离为一个或二个元素的数组，进行归并操作
        int mid = left + (right - left) / 2;

        mSort(arr, left, mid);
        mSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void mergeSort(int arr[], int N)
{
    mSort(arr, 0, N - 1);
}
