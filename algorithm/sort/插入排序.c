void insertSort(int arr[], const int N)
{
    for (int i = 1; i < N; ++i)
    {
        int temp = arr[i];
        int j = i;

        // 存在序列arr[j, i)均大于arr[i],就将arr[j, i]向右按环形移动一位
        while (j > 0 && arr[j - 1] > temp)
        {
            // 将arr[j - 1]的值向右移动到arr[j]上，首次进入此循环arr[j]的值存在temp中
            arr[j] = arr[j - 1];
            j--;
        }
        // 将arr[i]的值移动到arr[j]上

        if (j != i)
        {
            arr[j] = temp;
        }
    }
}
