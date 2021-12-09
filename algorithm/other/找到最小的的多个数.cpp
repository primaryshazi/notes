#include <iostream>

int partition(int arr[], int low, int high)
{
    int index = low;
    int standard = arr[high];

    for (int i = low; i < high; ++i)
    {
        if (arr[i] < standard)
        {
            std::swap(arr[index], arr[i]);
            ++index;
        }
    }
    std::swap(arr[high], arr[index]);

    return index;
}

void MinValueOfNum(int arr[], int length, int result[], int number)
{
    if (nullptr == arr || length <= 0 || nullptr == result || number <= 0)
    {
        return;
    }

    // 将比index位置小的元素均在index左边
    int index = partition(arr, 0, length - 1);
    int low = 0;
    int high = length - 1;

    // 当index与number - 1的值相等时，即左边为最小number个数
    while (index + 1 != number)
    {
        /**
         * 当index + 1大于所需长度时，将最大范围减1
         * 当index + 1小于所需长度时，将最小范围加1
         */
        if (index + 1 > number)
        {
            high = index - 1;
            index = partition(arr, low, high);
        }
        else
        {
            low = index + 1;
            index = partition(arr, low, high);
        }
    }

    for (int i = 0; i < number; i++)
    {
        result[i] = arr[i];
    }
}

int main()
{
    const int length = 10;
    const int number = 5;

    int arr[length] = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3 };
    int result[number] = {};

    MinValueOfNum(arr, length, result, number);

    /**
     * => 1
     * => 1
     * => 2
     * => 3
     * => 3
     */
    for (int i : result)
    {
        std::cout << i << std::endl;
    }

    return 0;
}
