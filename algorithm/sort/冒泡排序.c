void bubbleSort(int arr[], const int N)
{
    for (int i = 0; i < N - 1; ++i)
    {
        // 每轮循环将[0, N - 1 - i]中第最大的数放到arr[N - 1 - i]上
        // 并将从arr[0]开始的相邻逆序的两位交换一次
        for (int j = 0; j < N - 1 - i; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
