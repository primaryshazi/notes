#include <iostream>

int main(int argc, char const *argv[])
{
    int value = 1'1'1;
    // int value = 1'1'  // error
    // int value = '1'1  // error

    /**
     * => 111
     */
    std::cout << value << std::endl;

    return 0;
}
