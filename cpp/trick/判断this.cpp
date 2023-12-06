#include <iostream>

struct A
{
    int x = 0;
    int get_x()
    {
        if (this)
        {
            return x;
        }

        return 0;
    }
};

int get_x(A *ptr)
{
    if (ptr)
    {
        return ptr->x;
    }

    return 0;
}

int main()
{
    A *ptr = nullptr;
    std::cout << ptr->get_x() << std::endl;
    std::cout << get_x(ptr) << std::endl;

    return 0;
}
