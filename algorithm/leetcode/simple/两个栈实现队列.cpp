#include <iostream>
#include <stack>

class CQueue
{
public:
    CQueue() {}

    void appendTail(int value)
    {
        _in.push(value);
    }

    int deleteHead()
    {
        // 当出栈未空时，将入栈中的元素均置于出栈中
        if (_out.empty())
        {
            while (!_in.empty())
            {
                _out.push(_in.top());
                _in.pop();
            }
        }

        if (_out.empty())
        {
            return -1;
        }

        int value = _out.top();
        _out.pop();
        return value;
    }

private:
    std::stack<int> _in;
    std::stack<int> _out;
};

int main()
{
    CQueue que;

    for (int i = 0; i < 10; i++)
    {
        que.appendTail(i);
    }

    /**
     * => 0
     * => 1
     * => 2
     * => 3
     * => 4
     * => 5
     * => 6
     * => 7
     * => 8
     * => 9
     */
    for (int i = que.deleteHead(); i >= 0; i = que.deleteHead())
    {
        std::cout << i << std::endl;
    }

    return 0;
}
