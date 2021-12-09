#include <iostream>

template <typename T>
void Func(T t)
{
    std::cout << t << std::endl;
}

template <typename T>
class Test
{
    friend std::ostream &operator<<(std::ostream &os, const Test &)
    {
        os << "Test";
        return os;
    }
};

int main(int argc, char const *argv[])
{
    struct ST
    {
    };
    enum
    {
        ONE
    };
    
    /**
     * => Test
     */
    Func(Test<ST>());
    
    /**
     * => 0
     */
    Func(ONE);

    return 0;
}
