#include <iostream>
#include <stack>

class MinStack
{
public:
    void push(int value)
    {
        _minValue = std::min(value, _minValue);
        _stack.push(value);
        _minStack.push(_minValue);
    }

    void pop()
    {
        if (_stack.empty())
        {
            return;
        }

        _stack.pop();
        _minStack.pop();
        _minValue = (_minStack.empty() ? INT_MAX : _minStack.top());
    }

    int top()
    {
        return _stack.top();
    }

    int min()
    {
        return _minValue;
    }

private:
    int _minValue = INT_MAX;    // 当前最小值
    std::stack<int> _stack;     // 元素栈
    std::stack<int> _minStack;  // 每个元素入栈时的最小元素
};

int main()
{
    const int N = 10;
    MinStack ms;

    for (int i = 0; i < N; i++)
    {
        ms.push(N - i);
    }

    /**
     * => 1  1
     * => 2  2
     * => 3  3
     * => 4  4
     * => 5  5
     * => 6  6
     * => 7  7
     * => 8  8
     * => 9  9
     * => 10  10
     */
    for (int i = 0; i < N; i++)
    {
        std::cout << ms.top() << "  " << ms.min() << std::endl;
        ms.pop();
    }

    return 0;
}
