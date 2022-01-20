#include <iostream>
#include <stack>

class CQueue
{
public:
    CQueue() {}

    void appendTail(int value)
    {
        in_.push(value);
    }

    int deleteHead()
    {
        // 当出栈未空时，将入栈中的元素均置于出栈中
        if (out_.empty())
        {
            while (!in_.empty())
            {
                out_.push(in_.top());
                in_.pop();
            }
        }

        if (out_.empty())
        {
            return -1;
        }

        int value = out_.top();
        out_.pop();
        return value;
    }

private:
    std::stack<int> in_;
    std::stack<int> out_;
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
