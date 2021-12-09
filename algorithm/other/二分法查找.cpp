#include <iostream>
#include <vector>

int binarySearch(const std::vector<int> &nums, int target)
{
    int n = nums.size();
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = ((right - left) >> 1) + left;

        if (target < nums[mid])
        {
            right = mid - 1;
        }
        else if (target > nums[mid])
        {
            left = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int main()
{
    std::vector<int> nums = { 1, 2, 3, 4, 5 };

    /**
     * => 2
     * => 4
     * => 5
     */
    std::cout << binarySearch(nums, 3) << std::endl;
    std::cout << binarySearch(nums, 5) << std::endl;
    std::cout << binarySearch(nums, 6) << std::endl;

    return 0;
}
