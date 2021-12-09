#include <iostream>
#include <algorithm>
#include <vector>

std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
{
    int size = nums.size();
    std::vector<std::vector<int>> result;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < size - 2; ++i)
    {
        // 当非第一轮且当前元素与上一元素相同则不处理
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        int k = size - 1;   // 第三个元素从后向前遍历

        for (int j = i + 1; j < size - 1; ++j)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
            {
                continue;
            }
            // 第二个元素在第三个之前且三数之和大于0则第三后退
            while (j < k && nums[i] + nums[j] + nums[k] > 0)
            {
                --k;
            }
            if (j >= k)
            {
                break;
            }
            if (nums[i] + nums[j] + nums[k] == 0)
            {
                result.emplace_back(std::vector<int>{nums[i], nums[j], nums[k]});
            }
        }
    }

    return result;
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
    std::vector<int> vec1 = { -3, -2, -1, 0, 1, 2, 3 };
    std::vector<int> vec2 = { -3, -3, -2, -2, -1, -1 , 0, 0, 1, 1, 2, 2 ,3, 3 };
    std::vector<int> vec3 = { -1, 0, 1, -2, -3, 4, 5 };

    auto r1 = threeSum(vec1);
    auto r2 = threeSum(vec2);
    auto r3 = threeSum(vec3);

    /**
     * => -3 0 3
     * => -3 1 2
     * => -2 -1 3
     * => -2 0 2
     * => -1 0 1
     * =>
     * => -3 0 3
     * => -3 1 2
     * => -2 -1 3
     * => -2 0 2
     * => -2 1 1
     * => -1 -1 2
     * => -1 0 1
     * =>
     * => -3 -2 5
     * => -3 -1 4
     * => -1 0 1
     */
    for (auto v : r1)
    {
        print(v);
    }
    std::cout << std::endl;
    for (auto v : r2)
    {
        print(v);
    }
    std::cout << std::endl;
    for (auto v : r3)
    {
        print(v);
    }

    return 0;
}
