#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals)
{
    int n = static_cast<int>(intervals.size());
    if (n <= 1)
    {
        return intervals;
    }

    std::sort(intervals.begin(), intervals.end());

    std::vector<std::vector<int>> result;
    int pos = 0;    // 记录当前区间

    while (pos < n)
    {
        int right = intervals[pos][1];  // 当前区间右边界
        int next = pos + 1;             // 下一待合并区间

        // 若下一区间的左边界小于等于当前区间右边界，则持续合并至当前区间
        while (next < n && intervals[next][0] <= right)
        {
            // 合并后的右边界取最大值
            right = std::max(right, intervals[next][1]);
            next++;
        }

        // 将合并完成的当前区间存入
        result.emplace_back(std::vector<int>{ intervals[pos][0], right });
        // 从下一个待合并的区间开始
        pos = next;
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
    std::vector<std::vector<int>> intervals = {
        {2, 3},
        {2, 2},
        {3, 3},
        {1, 3},
        {5, 7},
        {2, 2},
        {4, 6}
    };

    /**
     * => { { 1, 3 }, { 4, 7 } }
     */
    std::cout << merge(intervals) << std::endl;

    return 0;
}
