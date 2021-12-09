#include <iostream>
#include <string>

int myAtoi(const std::string &s)
{
    int result = 0;
    int sign = 0;   // 标记正负数，无符号位时默认为正数

    for (auto ch : s)
    {
        if (ch == '+' || ch == '-')
        {
            if (sign != 0)
            {
                break;
            }
            sign = ch == '+' ? 1 : -1;
        }
        else if (std::isspace(ch))
        {
            if (sign != 0)
            {
                break;
            }
            continue;
        }
        else if (std::isdigit(ch))
        {
            if (sign == 0)
            {
                sign = 1;
            }
            int64_t tmp = static_cast<int64_t>(result) * 10 + ch - '0';

            if (tmp > INT_MAX)
            {
                result = sign == 1 ? INT_MAX : INT_MIN;
                sign = 1;
                break;
            }
            result = tmp;
        }
        else
        {
            break;
        }
    }

    return sign * result;
}

int main()
{
    /**
     * => 0
     * => 123
     * => -123
     * => 123
     * => 123
     * => 123
     * => 2147483647
     * => -2147483648
     */
    std::cout << myAtoi("a123") << std::endl;
    std::cout << myAtoi("   +123") << std::endl;
    std::cout << myAtoi("   -123") << std::endl;
    std::cout << myAtoi("123a456") << std::endl;
    std::cout << myAtoi("123+456") << std::endl;
    std::cout << myAtoi(" 123 456 ") << std::endl;
    std::cout << myAtoi("+12345678987654321") << std::endl;
    std::cout << myAtoi("-12345678987654321") << std::endl;

    return 0;
}
