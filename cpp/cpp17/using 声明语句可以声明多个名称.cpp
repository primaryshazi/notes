#include <iostream>
#include <string>

namespace A
{

std::string getA() { return "A"; }

} // namespace A

namespace B
{

std::string getB() { return "B"; }

} // namespace B

namespace C
{

std::string getC() { return "C"; }

} // namespace C

int main()
{
    using A::getA, B::getB, C::getC;

    /**
     * => A
     * => B
     * => C
     */
    std::cout << getA() << std::endl;
    std::cout << getB() << std::endl;
    std::cout << getC() << std::endl;

    return 0;
}
