#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target)
{
    if (nums.empty())
    {
        return {};
    }

    int length = nums.size();
    std::vector<std::vector<int>> result;
    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < length - 3; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        if (static_cast<int64_t>(nums[i]) + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
        {
            break;
        }
        if (static_cast<int64_t>(nums[i]) + nums[length - 3] + nums[length - 2] + nums[length - 1] < target)
        {
            continue;
        }
        for (int j = i + 1; j < length - 2; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
            {
                continue;
            }
            if (static_cast<int64_t>(nums[i]) + nums[j] + nums[j + 1] + nums[j + 2] > target)
            {
                break;
            }
            if (static_cast<int64_t>(nums[i]) + nums[j] + nums[length - 2] + nums[length - 1] < target)
            {
                continue;
            }
            int left = j + 1, right = length - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];

                /**
                 * 相等则记录
                 * 小于则移动左指针
                 * 大于则移动右指针
                 */
                if (sum == target)
                {
                    result.push_back({ nums[i], nums[j], nums[left], nums[right] });
                    // 找到下一个不与当前值相同的左值
                    while (left < right && nums[left] == nums[left + 1])
                    {
                        left++;
                    }
                    left++;
                    // 找到下一个不与当前值相同的右值
                    while (left < right && nums[right] == nums[right - 1])
                    {
                        right--;
                    }
                    right--;
                }
                else if (sum < target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
    }

    return result;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v)
{
    os << "{ ";
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        if (it != v.begin())
        {
            os << ", ";
        }
        os << *it;
    }
    os << " }";

    return os;
}

int main()
{
    std::vector<int> v1 = { -5, -4, -4, 0, 2, 2, 3, 3 };
    std::vector<int> v2 = { -5, -3, -1, 0, 2, 4 };
    std::vector<int> v3 = { -4, -2, 0, 1, 3, 5 };

    auto r1 = fourSum(v1, 0);
    auto r2 = fourSum(v2, 0);
    auto r3 = fourSum(v3, 0);

    /**
     * => { { -5, 0, 2, 3 }, { -4, 0, 2, 2 } }
     * => { { -5, -1, 2, 4 }, { -3, -1, 0, 4 } }
     * => { { -4, -2, 1, 5 }, { -4, 0, 1, 3 } }
     */
    std::cout << r1 << std::endl;
    std::cout << r2 << std::endl;
    std::cout << r3 << std::endl;

    return 0;
}
