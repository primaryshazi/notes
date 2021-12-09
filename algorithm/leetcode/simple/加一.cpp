#include <iostream>
#include <vector>

std::vector<int> plusOne(const std::vector<int> &digits)
{
    int length = digits.size();
    int index = length - 1;
    std::vector<int> result;

    while (index >= 0 && digits[index] == 9)
    {
        index--;
    }

    if (index < 0)
    {
        result.assign(length + 1, 0);
        result[0] = 1;
    }
    else
    {
        result.assign(length, 0);
        for (int i = 0; i <= index; i++)
        {
            result[i] = digits[i];
        }
        result[index] += 1;
    }

    return result;
}

template <typename T>
void print(const std::vector<T> &v)
{
    for (auto &t : v)
    {
        std::cout << t << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> v1 = { 1, 2, 3, 4 };
    std::vector<int> v2 = { 1, 2, 3, 9 };
    std::vector<int> v3 = { 1, 2, 9, 9 };
    std::vector<int> v4 = { 1, 9, 9, 9 };
    std::vector<int> v5 = { 9, 9, 9, 9 };

    /**
     * => 1 2 3 5
     * => 1 2 4 0
     * => 1 3 0 0
     * => 2 0 0 0
     * => 1 0 0 0
     */
    print(plusOne(v1));
    print(plusOne(v2));
    print(plusOne(v3));
    print(plusOne(v4));
    print(plusOne(v5));

    return 0;
}
