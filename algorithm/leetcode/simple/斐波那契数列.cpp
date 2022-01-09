#include <iostream>
#include <vector>

int fib(int n)
{
    if (n < 2)
    {
        return n;
    }

    int x = 0;
    int y = 0;
    int z = 1;
    for (int i = 2; i <= n; i++)
    {
        x = y;
        y = z;
        z = (x + y) % 1000000007;
    }
    return z;
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        std::cout << fib(i) << std::endl;
    }

    return 0;
}
