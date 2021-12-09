#include <iostream>

constexpr bool isEven(int value)
{
    return [&] { return value % 2 == 0; }();
}

int main()
{
    /**
     * => 1
     * => 0
     * => 1
     * => 0
     * => 1
     * => 0
     * => 1
     * => 0
     * => 1
     * => 0
     */
    for (int i = 0; i < 10; i++)
    {
        std::cout << isEven(i) << std::endl;
    }


    return 0;
}
