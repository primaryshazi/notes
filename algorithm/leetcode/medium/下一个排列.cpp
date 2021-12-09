#include <iostream>
#include <algorithm>
#include <vector>

void nextPermutation(std::vector<int> &nums)
{
    // 从后向前找到第一个小于右值的数
    int left = nums.size() - 2;
    while (left >= 0 && nums[left] >= nums[left + 1])
    {
        --left;
    }
    /**
     * 找到则进行右子数组处理后反转子数组
     * 未找到则直接反转整个数组
     */
    if (left >= 0)
    {
        // 从后向前找到第一个大于left索引的数，与之交换，形成从left + 1开始的递减序列
        int right = nums.size() - 1;
        while (right >= 0 && nums[left] >= nums[right])
        {
            --right;
        }
        std::swap(nums[left], nums[right]);
    }
    std::reverse(nums.begin() + left + 1, nums.end());
}

template <typename T>
void print(const std::vector<T> &v)
{
    for (auto &t : v)
    {
        std::cout << t << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> v1 = { 1, 2, 3, 4, 5 };
    std::vector<int> v2 = { 5, 4, 3, 2, 1 };
    std::vector<int> v3 = { 1, 3, 5, 4, 2 };

    /**
     * => 1 2 3 5 4
     * => 1 2 3 4 5
     * => 1 4 2 3 5
     */
    nextPermutation(v1);
    print(v1);
    nextPermutation(v2);
    print(v2);
    nextPermutation(v3);
    print(v3);

    return 0;
}
