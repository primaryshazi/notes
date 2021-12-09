#include <iostream>

typedef void (*NoexceptFuncType)() noexcept;
typedef void (*FuncType)();

int main()
{
    /**
     * => PDoFvvE
     * => PFvvE
     */
    std::cout << typeid(NoexceptFuncType).name() << std::endl;
    std::cout << typeid(FuncType).name() << std::endl;

    return 0;
}
