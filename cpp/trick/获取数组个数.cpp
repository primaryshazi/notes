#include <iostream>

template <typename T, int N>
size_t countof_1(T (&a)[N])
{
    return N;
}

template <typename T, size_t N>
size_t countof_2(T (&arr)[N])
{
    return std::extent<T[N]>::value;
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[][3] = {{1, 2}, {3, 4}, {5, 6}};

    std::cout << countof_1(arr1) << std::endl;
    std::cout << countof_2(arr1) << std::endl;

    std::cout << countof_1(arr2) << std::endl;
    std::cout << countof_2(arr2) << std::endl;

    return 0;
}
