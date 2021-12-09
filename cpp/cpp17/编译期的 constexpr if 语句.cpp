#include <iostream>

template <int SIZE, typename... Args>
bool IsRightLength(Args &&...args)
{
    if constexpr (SIZE == sizeof...(args))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    /**
     * => 1
     */
    std::cout << IsRightLength<3>(0, 0, 0) << std::endl;

    return 0;
}
