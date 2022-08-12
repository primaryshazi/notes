#include <iostream>

void AdjustOddEven(int arr[], int length)
{
    if (nullptr == arr || length < 2)
    {
        return;
    }

    int oddIndex = 0;               // 奇数索引
    int evenIndex = length - 1;     // 偶数索引

    while (oddIndex < evenIndex)
    {
        // 向右移动，直至第一个奇数
        while (oddIndex < evenIndex && (arr[oddIndex] & 01) == 0)
        {
            ++oddIndex;
        }

        // 向左移动，直至第一个偶数
        while (oddIndex < evenIndex && (arr[evenIndex] & 01) != 0)
        {
            --evenIndex;
        }

        // 将前半部分找到的奇数与后半部分找到的偶数进行交换
        if (oddIndex < evenIndex)
        {
            std::swap(arr[oddIndex], arr[evenIndex]);
        }
    }
}

int main()
{
    const int N = 10;
    int arr[N] = {};

    for (int i = 0; i < N; ++i)
    {
        arr[i] = i;
    }

    AdjustOddEven(arr, N);

    /**
     * => 8
     * => 2
     * => 6
     * => 4
     * => 5
     * => 3
     * => 7
     * => 1
     * => 9
     */
    for (int i = 0; i < N; ++i)
    {
        std::cout << arr[i] << std::endl;
    }

    return 0;
}
