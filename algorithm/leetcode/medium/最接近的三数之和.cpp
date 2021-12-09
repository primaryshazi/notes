#include <iostream>
#include <algorithm>
#include <vector>

int threeSumClosest(std::vector<int> &nums, int target)
{
    int size = nums.size();
    int64_t result = INT_MAX;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < size; ++i)
    {
        // 当非第一轮且当前元素与上一元素相同则不处理
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        int j = i + 1;
        int k = size - 1;

        // 利用双指针
        while (j < k)
        {
            int value = nums[i] + nums[j] + nums[k];
            if (value == target)
            {
                return target;
            }

            // 记录最好的结果
            if (std::abs(value - target) < std::abs(result - target))
            {
                result = value;
            }

            /**
             * 找到第一个不予本身相同的下一个值
             * 当值比目标值大时，需要向前移动k，使值变小
             * 当值比目标值小时，需要向后移动j，使值变大
             */
            if (value > target)
            {
                int x = k - 1;
                while (j < x && nums[x] == nums[k])
                {
                    --x;
                }
                k = x;
            }
            else
            {
                int x = j + 1;
                while (x < k && nums[x] == nums[j])
                {
                    ++x;
                }
                j = x;
            }
        }
    }

    return result;
}


int main()
{
    std::vector<int> vec = { -5, -3, -3, -1, 1, 3, 3, 3 };

    /**
     * => 0  -1
     * => 1  1
     * => 2  1
     * => 3  3
     * => 4  3
     * => 5  5
     * => 6  5
     * => 7  7
     * => 8  7
     * => 9  9
     */
    for (int i = 0; i < 10; i++)
    {
        std::cout << i << "  " << threeSumClosest(vec, i) << std::endl;
    }

    return 0;
}
