#include <iostream>
#include <stack>

class MinStack
{
private:
    std::stack<int> m_stack;    // 储存元素
    std::stack<int> m_minStack; // 记录每一次存入时的最小元素
    int m_minValue = INT_MAX;   // 记录当前最小元素

public:
    void Push(int value)
    {
        m_stack.push(value);

        if (value < m_minValue)
        {
            m_minValue = value;
        }
        m_minStack.push(m_minValue);
    }

    void Pop()
    {
        if (!m_stack.empty())
        {
            m_stack.pop();
            m_minStack.pop();
        }

        if (!m_minStack.empty())
        {
            m_minValue = m_minStack.top();
        }
        else
        {
            m_minValue = INT_MAX;
        }
    }

    int Min()
    {
        return m_minValue;
    }
};

int main()
{
    const int N = 10;
    MinStack ms;

    for (int i = 0; i < N; i++)
    {
        ms.Push(N - i);
    }

    for (int i = 0; i < N; i++)
    {
        ms.Pop();
        std::cout << ms.Min() << std::endl;
    }

    return 0;
}
