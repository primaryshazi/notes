#include <iostream>
#include <stack>

class MinStack
{
public:
    void push(int value)
    {
        _stack.push(value);

        if (value < _minValue)
        {
            _minValue = value;
        }
        _minStack.push(_minValue);
    }

    void pop()
    {
        if (!_stack.empty())
        {
            _stack.pop();
            _minStack.pop();
        }

        if (!_minStack.empty())
        {
            _minValue = _minStack.top();
        }
        else
        {
            _minValue = INT_MAX;
        }
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
    std::stack<int> _stack;    // 储存元素
    std::stack<int> _minStack; // 记录每一次存入时的最小元素
    int _minValue = INT_MAX;   // 记录当前最小元素
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
