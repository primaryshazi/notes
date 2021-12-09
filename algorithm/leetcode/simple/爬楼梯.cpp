#include <iostream>

int climbStairs(int n)
{
    int x = 0;
    int y = 0;
    int z = 1;

    for (int i = 1; i <= n; i++)
    {
        x = y;
        y = z;
        z = x + y;
    }

    return z;
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        std::cout << i << "  " << climbStairs(i) << std::endl;
    }

    return 0;
}
