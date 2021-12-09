#include <iostream>

struct X
{
    int i;
    int j;
    int k;
};

int main(int argc, char const *argv[])
{
    // 二者等效
    X a[] = {1, 2, 3, 4, 5, 6};
    X b[] = {{1, 2, 3}, {4, 5, 6}};

    /**
     * => 1 2 3
     * => 4 5 6
     * => 1 2 3
     * => 4 5 6
     */
    std::cout << a[0].i << " " << a[0].j << " " << a[0].k << std::endl;
    std::cout << a[1].i << " " << a[1].j << " " << a[1].k << std::endl;
    std::cout << b[0].i << " " << b[0].j << " " << b[0].k << std::endl;
    std::cout << b[1].i << " " << b[1].j << " " << b[1].k << std::endl;

    return 0;
}
