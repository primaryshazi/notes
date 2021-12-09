void shellSort(int arr[], const int N)
{
    // 将元素分成floor(N/span)组，从步进1改为步进span进行插入排序处理
    for (int span = N / 2; span > 0; span /= 2)
    {
        for (int i = span; i < N; ++i)
        {
            int temp = arr[i];
            int j = i;

            while (j > span && arr[j - span] > temp)
            {
                arr[j] = arr[j - span];
                j -= span;
            }
            if (j != i)
            {
                arr[j] = temp;
            }
        }
    }
}
