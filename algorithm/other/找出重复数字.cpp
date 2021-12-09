#include <iostream>

int RepeatitionNum(int arr[], const int c_length)
{
    if (nullptr == arr || c_length <= 0)
    {
        return -1;
    }

    // 确保数组各元素均在[0, c_length -1]的范围内
    for (int i = 0; i < c_length; ++i)
    {
        if (arr[i] < 0 || arr[i] > c_length - 1)
        {
            return -1;
        }
    }

    // 对数据元素进行排序
    for (int i = 0; i < c_length; ++i)
    {
        // 由于索引范围与元素范围一致，故将每个元素移动到与其值相同的索引位置
        while (arr[i] != i)
        {
            // 当前元素与索引不等，而元素值索引位置的数据与当前值相等则重复
            if (arr[i] == arr[arr[i]])
            {
                return arr[i];
            }
            std::swap(arr[i], arr[arr[i]]);
        }
    }

    return -1;
}

int main()
{
    // 元素范围与索引范围一致
    int arr[] = {1, 3, 5, 4, 3, 2, 6, 7};

    /**
     * => 3
     */
    std::cout << RepeatitionNum(arr, sizeof(arr) / sizeof(arr[0])) << std::endl;

    return 0;
}
