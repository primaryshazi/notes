#include <iostream>
#include <chrono>

int main()
{
    /**
     * => even : 1625563611056386700
     */
    if (auto epoch = std::chrono::system_clock::now().time_since_epoch().count(); epoch % 2 == 0)
    {
        std::cout << "even : " << epoch << std::endl;
    }
    else
    {
        std::cout << "odd : " << epoch << std::endl;
    }

    /**
     * => even : 0
     */
    switch (auto evenOddCase = std::chrono::system_clock::now().time_since_epoch().count() % 2)
    {
    case 0:
        std::cout << "even : " << evenOddCase << std::endl;
        break;
    case 1:
        std::cout << "odd : " << evenOddCase << std::endl;
        break;
    default:
        break;
    }

    return 0;
}
