#include <iostream>
#include <vector>
#include <queue>
#include <deque>

std::vector<int> GetWindowMax(const std::vector<int> &vecNum, int windowSize)
{
    if (vecNum.empty() || windowSize <= 0)
    {
        return {};
    }

    std::vector<int> vecMax;    // 记录窗口最大值
    std::deque<int> deqMax;     // 记录可能最大值
    std::queue<int> queWin;     // 记录滑动窗口

    for (int value : vecNum)
    {
        queWin.emplace(value);

        if (queWin.size() > windowSize)
        {
            // 当前要推出的窗口值于最大值相同则推出最大值
            if (queWin.front() == deqMax.front())
            {
                deqMax.pop_front();
            }
            queWin.pop();
        }
        else if (queWin.size() < windowSize)
        {
            deqMax.emplace_back(value);

            continue;
        }

        if (!deqMax.empty())
        {
            /**
             * 若当前值不大于最大值，则将尾部所有小于此值的全部推出，并从尾部插入当前值
             * 若当前值大于最大值，则将余下值全部推出，并从尾部插入当前值
             */
            if (value <= deqMax.front())
            {
                while (!deqMax.empty() && value > deqMax.back())
                {
                    deqMax.pop_back();
                }
                deqMax.emplace_back(value);
            }
            else
            {
                deqMax.clear();
                deqMax.emplace_back(value);
            }
        }
        else
        {
            deqMax.emplace_back(value);
        }

        vecMax.emplace_back(deqMax.front());
    }

    return vecMax;
}

int main()
{
    std::vector<int> vecNum = { 2, 3, 4, 2, 6, 2, 5, 1 };
    std::vector<int> vecMax = GetWindowMax(vecNum, 3);

    /**
     * => 4
     * => 4
     * => 6
     * => 6
     * => 6
     * => 5
     */
    for (int value : vecMax)
    {
        std::cout << value << std::endl;
    }

    return 0;
}
