#include <iostream>
#include <cmath>

bool IsPerfectNumber(const unsigned int num)
{
    if (num < 2)
    {
        return false;
    }

    unsigned int factorSum = 1;
    unsigned int factor = 0;
    unsigned int sqrtNum = (unsigned int)sqrt(num);

    for (unsigned u = 2; u <= sqrtNum; u++)
    {
        if (num % u == 0)
        {
            factor = num / u;
            factorSum += u;
            // 因数不等于本身且不与除数相等
            if (factor != num && factor != u)
            {
                factorSum += factor;
            }
        }
    }

    return num == factorSum;
}

int main()
{
    /**
     * => 6
     * => 28
     * => 496
     * => 8128
     */
    for (int i = 0; i < 10000; ++i)
    {
        if (IsPerfectNumber(i))
        {
            std::cout << i << std::endl;
        }
    }

    return 0;
}
