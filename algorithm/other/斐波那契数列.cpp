#include <iostream>

uint64_t FibonacciByRecursive(int n)
{
    if (n < 2)
    {
        return 1;
    }

    return FibonacciByRecursive(n - 1) + FibonacciByRecursive(n - 2);
}

uint64_t FibonacciByCycle(int n)
{
    int fn_2 = 0; // f(n - 2)
    int fn_1 = 0; // f(n - 1)
    int fn = 1;   // f(n)

    for (int i = 1; i <= n; ++i)
    {
        fn_2 = fn_1;
        fn_1 = fn;
        fn = fn_1 + fn_2;
    }

    return fn;
}

int main()
{
    const int N = 16;

    /**
     * => 1597
     * => 1597
     */
    std::cout << FibonacciByRecursive(N) << std::endl;
    std::cout << FibonacciByCycle(N) << std::endl;

    return 0;
}
