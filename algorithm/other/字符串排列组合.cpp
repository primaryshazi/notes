#include <iostream>
#include <string>

void PermutationCore(char *str, char *begin)
{
    if ('\0' == *begin)
    {
        std::cout << str << std::endl;
    }
    else
    {
        for (char *ptr = begin; *ptr != '\0'; ++ptr)
        {
            std::swap(*ptr, *begin);
            PermutationCore(str, begin + 1);
            std::swap(*ptr, *begin);
        }
    }
}

void Permutation(char *str)
{
    if (nullptr == str)
    {
        return;
    }
    PermutationCore(str, str);
}

int main()
{
    char str[] = "1234";

    /**
     * => 1234
     * => 1243
     * => 1324
     * => 1342
     * => 1432
     * => 1423
     * => 2134
     * => 2143
     * => 2314
     * => 2341
     * => 2431
     * => 2413
     * => 3214
     * => 3241
     * => 3124
     * => 3142
     * => 3412
     * => 3421
     * => 4231
     * => 4213
     * => 4321
     * => 4312
     * => 4132
     * => 4123
     */
    Permutation(str);

    return 0;
}
