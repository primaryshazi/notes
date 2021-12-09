#include <iostream>
#include <vector>
#include <string>

void generateParenthesisCore(int left, int right, int n, std::string &str, std::vector<std::string> &result)
{
    // 当括号均已填完时，则存储并返回
    if (str.size() == 2 * n)
    {
        result.emplace_back(str);
        return;
    }

    // 当左括号尚未填完时，可填入左括号
    if (left < n)
    {
        str.push_back('(');
        generateParenthesisCore(left + 1, right, n, str, result);
        str.pop_back();
    }
    // 当右括号小于左括号时，可填入右括号
    if (right < left)
    {
        str.push_back(')');
        generateParenthesisCore(left, right + 1, n, str, result);
        str.pop_back();
    }
}

std::vector<std::string> generateParenthesis(int n)
{
    if (n <= 0)
    {
        return {};
    }

    std::string str;
    std::vector<std::string> result;

    generateParenthesisCore(0, 0, n, str, result);

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
    /**
     * => ()
     * => (()) ()()
     * => ((())) (()()) (())() ()(()) ()()()
     * => (((()))) ((()())) ((())()) ((()))() (()(())) (()()()) (()())() (())(()) (())()() ()((())) ()(()()) ()(())() ()()(()) ()()()()
     */
    for (int i = 0; i < 5; i++)
    {
        print(generateParenthesis(i));
    }

    return 0;
}
