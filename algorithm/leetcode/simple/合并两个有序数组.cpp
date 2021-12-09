#include <iostream>
#include <vector>

void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
{
    int mIndex = m - 1;
    int nIndex = n - 1;
    int index = m + n - 1;

    while (mIndex > 0 || nIndex >= 0)
    {
        if (mIndex < 0)
        {
            nums1[index] = nums2[nIndex];
            --nIndex;
        }
        else if (nIndex < 0)
        {
            nums1[index] = nums1[mIndex];
            --mIndex;
        }
        else
        {
            if (nums1[mIndex] > nums2[nIndex])
            {
                nums1[index] = nums1[mIndex];
                --mIndex;
            }
            else
            {
                nums1[index] = nums2[nIndex];
                --nIndex;
            }
        }
        --index;
    }
}

int main()
{
    std::vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7, 0, 0, 0};
    std::vector<int> nums2 = {3, 4, 5};

    merge(nums1, nums1.size() - nums2.size(), nums2, nums2.size());

    /**
     * => 1
     * => 2
     * => 3
     * => 3
     * => 4
     * => 4
     * => 5
     * => 5
     * => 6
     * => 7
     */
    for (auto i : nums1)
    {
        std::cout << i << std::endl;
    }

    return 0;
}
