#include <iostream>

int ReplaceBlank(char str[], int maxLen, const char *replace)
{
    int sLength = 0;
    int rLenth = 0;

    if (nullptr == str || nullptr == replace || (sLength = strlen(str)) <= 0 || (rLenth = strlen(replace)) <= 0)
    {
        return -1;
    }

    int blankCount = 0; // 空格个数

    for (int i = 0; i < sLength; ++i)
    {
        if (' ' == str[i])
        {
            ++blankCount;
        }
    }

    // 判断最大长度是否可以容纳替换之后的长度
    if (maxLen < sLength + (rLenth - 1) * blankCount)
    {
        return -1;
    }

    int newIndex = sLength + (rLenth - 1) * blankCount - 1; // 新字符串索引
    int originIndex = sLength - 1;                          // 源字符串索引

    // 从后向前遍历
    while (originIndex >= 0)
    {
        /**
         * 若当前字符为空格，则将新索引前进替换字符串长度，并将替换字符串拷贝于新索引之前
         * 若当前字符不为空格，则将源索引字符拷贝于新索引处
         */
        if (' ' == str[originIndex])
        {
            newIndex -= rLenth;
            memcpy(str + newIndex + 1, replace, rLenth);
        }
        else
        {
            str[newIndex] = str[originIndex];
            --newIndex;
        }
        --originIndex;
    }
}

int main()
{
    const int N = 64;
    char str[N] = "Hello World! Are You OK?";

    ReplaceBlank(str, N - 1, "==");

    /**
     * => Hello==World!==Are==You==OK?
     */
    std::cout << str << std::endl;

    return 0;
}
