#include <iostream>

int main(int argc, char const *argv[])
{
    int value = 10;

    /**
     * => 1 2
     * => 10 10
     * => 20
     */
    [x = 1, y = 2]() { std::cout << x << " " << y << std::endl; }();
    [&x = value, &y = value]() { std::cout << x << " " << y << std::endl; x += y; }();
    [value]() { std::cout << value << std::endl; }();

    return 0;
}
