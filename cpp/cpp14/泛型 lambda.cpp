#include <iostream>

int main(int argc, char const *argv[])
{
    auto func = [](auto value) -> auto { return value * value; };

    /**
     * => 100
     */
    std::cout << func(10) << std::endl;

    return 0;
}
