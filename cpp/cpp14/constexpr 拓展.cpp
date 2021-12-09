#include <iostream>

// 允许判断
const bool Func(bool flag)
{
    if (flag)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 允许循环
constexpr int Func(int value)
{
    int count = 0;

    for (int i = 0; i < value; i++)
    {
        count += i;
    }

    return count;
}

int main(int argc, char const *argv[])
{
    /**
     * => 45
     * => 1
     */
    std::cout << Func(10) << std::endl;
    std::cout << Func(true) << std::endl;

    return 0;
}
