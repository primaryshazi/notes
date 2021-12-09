//找到第n小的元素把它交换到arr[n - 1]位置上
void selectSort(int arr[], const int N)
{
    for (int i = 0; i < N; ++i)
    {
        int index = i;

        //找到剩余元素中最小的那个
        for (int j = i + 1; j < N; ++j)
        {
            if (arr[index] > arr[j])
            {
                index = j;
            }
        }

        //当找到比arr[i]小的元素与之交换
        if (index != i)
        {
            int temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;
        }
    }
}
