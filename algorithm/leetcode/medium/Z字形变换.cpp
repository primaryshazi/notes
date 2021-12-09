#include <iostream>
#include <string>
#include <vector>

std::string convert(const std::string &s, int numRows)
{
    if (numRows <= 1)
    {
        return s;
    }

    std::vector<std::string> rowStr(std::min(numRows, int(s.size())));    // 记录排列之后的每行的字符
    int curRow = 0;
    bool isDown = false;

    for (auto c : s)
    {
        rowStr[curRow] += c;
        // 当前行为第一行或者最后一行时，调转反向
        if (curRow == 0 || curRow == numRows - 1)
        {
            isDown = !isDown;
        }
        curRow += isDown ? 1 : -1;
    }

    std::string ret;
    for (auto row : rowStr)
    {
        ret += row;
    }

    return ret;
}

int main()
{
    /**
     * => ABCDEFGHIJKLMN
     * => ACEGIKMBDFHJLN
     * => AEIMBDFHJLNCGK
     * => AGMBFHLNCEIKDJ
     * => AIBHJCGKDFLNEM
     */
    for (int i = 0; i < 5; i++)
    {
        std::cout << convert("ABCDEFGHIJKLMN", i + 1) << std::endl;
    }

    return 0;
}