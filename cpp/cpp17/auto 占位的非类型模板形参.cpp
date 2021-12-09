#include <iostream>

template <typename T, auto A>
struct Test
{
public:
    void TypeInfo()
    {
        std::cout << typeid(T).name() << std::endl;
        std::cout << typeid(A).name() << std::endl;
        std::cout << A << std::endl;
    }
};

int main()
{
    Test<int, 0xffffffff> t;

    /**
     * => int
     * => unsigned int
     * => 4294967295
     */
    t.TypeInfo();

    return 0;
}
