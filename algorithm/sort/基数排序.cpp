#include <vector>
#include <algorithm>
#include <cmath>

void radixSort(int arr[], int N)
{
    int max = *std::max_element(arr, arr + N - 1); // 获取最大的元素
    int digit = std::floor(log10(max)) + 1;        // 获取最大元素的位数
    std::vector<std::vector<int>> radix;

    radix.resize(10);

    // 从个位数开始排序
    for (int d = 0; d < digit; d++)
    {
        for (int i = 0; i < N; ++i)
        {
            // 获取指定位数上的值
            int index = arr[i] % int(pow(10, d + 1)) / pow(10, d);

            radix[index].emplace_back(arr[i]);
        }

        // 指定基数排序后的值重新赋值与数组
        for (size_t i = 0, index = 0; i < radix.size(); ++i)
        {
            for (size_t j = 0; j < radix[i].size(); ++j)
            {
                arr[index++] = radix[i][j];
            }
            radix[i].clear();
        }
    }
}
