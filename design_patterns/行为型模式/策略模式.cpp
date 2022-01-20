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
public:
    Calculator(const std::shared_ptr<Operator> &c_spOp) : wpOP_(c_spOp) {}

    virtual ~Calculator() {}

    int exec(const int first, const int second)
    {
        return !wpOP_.expired() && wpOP_.lock() ? wpOP_.lock()->exec(first, second) : 0;
    }

private:
    std::weak_ptr<Operator> wpOP_;
};

int main()
{
    std::shared_ptr<Operator> spAdd = std::make_shared<AdditionOp>();
    std::shared_ptr<Operator> spSub = std::make_shared<SubtractOp>();

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
