#include <iostream>

template <typename... Args>
auto LeftFold(Args &&...args)
{
    /**
     * 等效于((((1 + 2) + 3) + 4) + 5)
     */
    return (... + args);
}

template <typename... Args>
auto RightFold(Args &&...args)
{
    /**
     * 等效于(6 + (7 + (8 + (9 + 10))))
     */
    return (args + ...);
}

template <typename... Args>
auto LeftDoubleFold(Args &&...args)
{
    /**
     * 等效于(((((100 + 1) + 2) + 3) + 4) + 5)
     */
    return (100 + ... + args);
}

template <typename... Args>
auto RightDoubleFold(Args &&...args)
{
    /**
     * 等效于(6 + (7 + (8 + (9 + (10 + 100)))))
     */
    return (args + ... + 100);
}

template <typename... Args>
auto Print(Args &&...args)
{
    (std::cout << ... << args) << std::endl;
}

int main()
{
    /**
     * => 15
     * => 40
     * => 115
     * => 140
     * => ABCDEFG
     */
    std::cout << LeftFold(1, 2, 3, 4, 5) << std::endl;
    std::cout << RightFold(6, 7, 8, 9, 10) << std::endl;
    std::cout << LeftDoubleFold(1, 2, 3, 4, 5) << std::endl;
    std::cout << RightDoubleFold(6, 7, 8, 9, 10) << std::endl;

    Print("A", "B", "C", "D", "E", "F", "G");

    return 0;
}
