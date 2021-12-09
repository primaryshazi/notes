#include <iostream>
#include <memory>
#include <string>

class Operator
{
public:
    virtual int exec(const int first, const int second) = 0;
};

class AdditionOp : public Operator
{
public:
    virtual int exec(const int first, const int second) override { return first + second; }
};

class SubtractOp : public Operator
{
public:
    virtual int exec(const int first, const int second) override { return first - second; }
};

class Calculator
{
private:
    std::weak_ptr<Operator> _wpOp;

public:
    Calculator(const std::shared_ptr<Operator> &c_spOp) : _wpOp(c_spOp) {}

    virtual ~Calculator() {}

    int exec(const int first, const int second)
    {
        return !_wpOp.expired() && _wpOp.lock() ? _wpOp.lock()->exec(first, second) : 0;
    }
};

int main()
{
    std::shared_ptr<Operator> spAdd{ new AdditionOp{} };
    std::shared_ptr<Operator> spSub{ new SubtractOp{} };

    /**
     * => 3
     * => -1
     * => 0
     */
    std::cout << Calculator(spAdd).exec(1, 2) << std::endl;
    std::cout << Calculator(spSub).exec(1, 2) << std::endl;
    std::cout << Calculator(nullptr).exec(1, 2) << std::endl;

    return 0;
}
