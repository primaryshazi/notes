#include <iostream>
#include <vector>

int main()
{
    std::vector vec{1, 2, 3};
    auto value = std::vector(vec);

    /**
     * => class std::vector<int,class std::allocator<int> >
     * => class std::vector<int,class std::allocator<int> >
     */
    std::cout << typeid(vec).name() << std::endl;
    std::cout << typeid(value).name() << std::endl;

    return 0;
}
