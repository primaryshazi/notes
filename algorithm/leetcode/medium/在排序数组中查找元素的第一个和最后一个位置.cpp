#include <iostream>
#include <vector>

int searchRangeCore(const std::vector<int> &nums, int target, bool isLower)
{
    int length = nums.size();
    int left = 0;
    int right = length - 1;
    int index = length;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] > target || (isLower && nums[mid] == target))
        {
            right = mid - 1;
            index = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    return index;
}

std::vector<int> searchRange(const std::vector<int> &nums, int target)
{
    int left = searchRangeCore(nums, target, true);         // 找到第一个大于等于目标值的索引
    int right = searchRangeCore(nums, target, false) - 1;   // 找到第一个大于目标值的索引
    if (left <= right && left >= 0 && right < nums.size() && nums[left] == target && nums[right] == target)
    {
        return { left, right };
    }
    return { -1, -1 };
}

int main()
{
    std::vector<int> v1 = { 1, 2, 3, 4, 5 };
    std::vector<int> v2 = { 1, 2, 3, 3, 4, 5 };
    std::vector<int> v3 = { 3, 3, 3, 3, 3 };

    auto r1 = searchRange(v1, 3);
    auto r2 = searchRange(v2, 3);
    auto r3 = searchRange(v3, 3);
    auto r4 = searchRange(v3, 0);

    /**
     * => 2  2
     * => 2  3
     * => 0  4
     * => -1  -1
     */
    std::cout << r1[0] << "  " << r1[1] << std::endl;
    std::cout << r2[0] << "  " << r2[1] << std::endl;
    std::cout << r3[0] << "  " << r3[1] << std::endl;
    std::cout << r4[0] << "  " << r4[1] << std::endl;

    return 0;
}
