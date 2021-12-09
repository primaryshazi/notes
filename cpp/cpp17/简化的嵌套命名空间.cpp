#include <iostream>

namespace A::B
{
void HelloWorld()
{
    std::cout << "Hello World!" << std::endl;
}
} // namesapce A::B

int main()
{
    /**
     * => Hello World!
     */
    A::B::HelloWorld();

    return 0;
}
