#include <iostream>
#include <atomic>

/**
 * 指示函数不返回
 */
[[noreturn]] void noReturn()
{
    exit(0);
}

/**
 * 指示释放消费 std::memory_order 中的依赖链传入和传出该函数
 */
template <typename T>
[[carries_dependency]] bool LoadValue(std::atomic<T>& atc)
{
    return atc.load(std::memory_order_consume);
}

int main(int argc, char const* argv[])
{
    std::atomic_int ai = 10;

    std::cout << LoadValue(ai) << std::endl;
    noReturn();

    return 0;
}
