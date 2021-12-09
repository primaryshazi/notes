void swapValue(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void buildHeap(int arr[], int N, int index)
{
    int father = index;         // 父节点索引
    int lChild = 2 * index + 1; // 左子节点索引
    int rChild = 2 * index + 2; // 右子节点索引

    // 当左子节点值大于父节点则父节点值为左子节点
    if (lChild < N && arr[lChild] > arr[father])
    {
        father = lChild;
    }

    // 当右子节点值大于父节点则右节点值为右子节点
    if (rChild < N && arr[rChild] > arr[father])
    {
        father = rChild;
    }

    // 若子节点大于父节点，则互换父节点与子节点值
    if (father != index)
    {
        swapValue(arr + index, arr + father);
        buildHeap(arr, N, father); // 父节点与子节点交换后子节点也需调整
    }
}

void heapSort(int arr[], int N)
{
    // 构建一个最大堆
    for (int i = N - 1; i >= 0; i--)
    {
        buildHeap(arr, N, i);
    }

    /**
     * 将堆顶最大元素与堆尾元素互换
     * 以arr[0, N - 1 - i]构建一个最大堆
     * 余下最大元素依次被放在数组尾部
     */
    for (int i = N - 1; i > 0; i--)
    {
        swapValue(arr, arr + i);
        buildHeap(arr, i, 0);
    }
}
