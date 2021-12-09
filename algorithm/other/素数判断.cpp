#include <iostream>
#include <cmath>

bool IsPrime(const unsigned int num)
{
    if (num < 2)
    {
        return false;
    }

    unsigned int sqrtNum = (unsigned int)sqrt(num);

    for (unsigned int u = 2; u <= sqrtNum; u++)
    {
        if (num % u == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    /**
     * => 2
     * => 3
     * => 5
     * => 7
     * => 11
     * => 13
     * => 17
     * => 19
     * => 23
     * => 29
     * => 31
     * => 37
     * => 41
     * => 43
     * => 47
     * => 53
     * => 59
     * => 61
     * => 67
     * => 71
     * => 73
     * => 79
     * => 83
     * => 89
     * => 97
     */
    for (int i = 0; i < 100; ++i)
    {
        if (IsPrime(i))
        {
            std::cout << i << std::endl;
        }
    }

    return 0;
}
