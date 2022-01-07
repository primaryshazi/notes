#include <iostream>
#include <unordered_set>

int squareSum(int n)
{
    int sum = 0;
    while (n > 0)
    {
        int mod = n % 10;
        n /= 10;
        sum += mod * mod;
    }
    return sum;
}

bool isHappy(int n)
{
    // 循环处理，数字每位数的平方和为1或者出现循环
    std::unordered_set<int> unorder;
    int result = n;
    while (result != 1 && unorder.count(result) == 0)
    {
        unorder.emplace(result);
        result = squareSum(result);
    }

    return result == 1;
}

int main()
{
    for (int i = 0; i < 1000; i++)
    {
        if (isHappy(i))
        {
            std::cout << i << std::endl;
        }
    }

    return 0;
}
