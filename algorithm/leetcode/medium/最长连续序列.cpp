#include <iostream>
#include <vector>
#include <unordered_set>

int longestConsecutive(std::vector<int> &nums)
{
    std::unordered_set<int> unorder;

    for (auto i : nums)
    {
        unorder.emplace(i);
    }

    int maxLen = 0;
    for (auto i : nums)
    {
        // 当i-1存在时，则在计算i-1时就会计算到i，可以跳过
        if (unorder.count(i - 1) == 0)
        {
            int curLen = 1;

            // 当i+1存在时则继续查找
            while (unorder.count(i + 1) > 0)
            {
                i++;
                curLen++;
            }

            maxLen = std::max(curLen, maxLen);
        }
    }

    return maxLen;
}

int main()
{
    std::vector<int> vi = { 0, 3, 7, 2, 5, 8, 4, 6, 0, 1 };

    /**
     * => 9
     */
    std::cout << longestConsecutive(vi) << std::endl;

    return 0;
}
