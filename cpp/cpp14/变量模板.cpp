#include <iostream>

template <typename T>
constexpr T SZ_PI = 3.1415926535897932385;

template <typename T>
T Perimeter(const T c_radius)
{
    return SZ_PI<T> * c_radius * 2;
}

int main(int argc, char const *argv[])
{
    int radius1 = 1;
    double radius2 = 0.99;

    /**
     * => 6
     * => 6.22035
     */
    std::cout << Perimeter(radius1) << std::endl;
    std::cout << Perimeter(radius2) << std::endl;

    return 0;
}
