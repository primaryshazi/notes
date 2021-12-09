#include <iostream>

// 虚函数不允许
auto Func(int value = 0)
{
    // return {1, 2, 3};   // error

    if (value % 2)
    {
        return 1;
    }
    else
    {
        return 0;
        // return 0.1; // error
    }
}

int main(int argc, char const *argv[])
{
    /**
     * => i
     */
    std::cout << typeid(Func()).name() << std::endl;

    return 0;
}
