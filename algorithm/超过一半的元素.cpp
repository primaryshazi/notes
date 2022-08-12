#include <iostream>

int HalfNum(int arr[], int N)
{
    int number = 0;
    int count = 0;

    for (int i = 0; i < N; ++i)
    {
        // 当计数减至0时表示记录元素不是最多元素，重新开始记录
        if (0 == count)
        {
            number = arr[i];
        }

        // 若当前元素与记录元素相同则将记录数加1，否则减1
        if (number == arr[i])
        {
            ++count;
        }
        else
        {
            --count;
        }
    }

    return number;
}

int main()
{
    // 假设一定有超过一半的相同元素
    const int N = 5;
    int arr[N] = {1, 0, 1, 0, 1};

    /**
     * => 1
     */
    std::cout << HalfNum(arr, N) << std::endl;

    return 0;
}
