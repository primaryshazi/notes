#include <iostream>
#include <string>
#include <vector>

int strStr(const std::string &source, const std::string &target)
{
    int n = source.size();
    int m = target.size();

    if (m == 0)
    {
        return 0;
    }

    std::vector<int> next(m);

    // 计算next数组，记录每一个字符在目标串中，最长匹配前缀的位置
    for (int i = 1, j = 0; i < m; i++)
    {
        while (j > 0 && target[i] != target[j])
        {
            j = next[j - 1];
        }
        if (target[i] == target[j])
        {
            j++;
        }
        next[i] = j;
    }

    for (int i = 0, j = 0; i < n; i++)
    {
        // 当出现不等时将目标指针移动至目标串前缀匹配处，从此开始继续比较
        while (j > 0 && source[i] != target[j])
        {
            j = next[j - 1];
        }

        // 当相等时则目标指针加一，继续比较
        if (source[i] == target[j])
        {
            j++;
        }
        if (j == m)
        {
            return i - m + 1;
        }
    }

    return -1;
}

int main()
{
    std::string source = "abccbabc";
    std::string target = "ba";

    /**
     * => 5
     */
    std::cout << strStr(source, target) << std::endl;

    return 0;
}
