#include <iostream>
#include <memory>
#include <string>

class Computer
{
protected:
    int _max;
    std::weak_ptr<Computer> _wpPC;

protected:
    Computer() : _max(0) {}

public:
    virtual ~Computer() {}

    virtual void assign(const std::shared_ptr<Computer> &c_spPC) = 0;

    virtual void work(int value) = 0;
};

class SuperComputer : public Computer
{
public:
    SuperComputer(const int c_max) : Computer() { _max = c_max; }

    virtual ~SuperComputer() {}

    virtual void assign(const std::shared_ptr<Computer> &c_spPC) override { _wpPC = c_spPC; }

    virtual void work(int value) override
    {
        if (value <= _max)
        {
            printf("[%d] : I can do [%d]\n", _max, value);
        }
        else if (!_wpPC.expired() && _wpPC.lock())
        {
            printf("[%d] : I give [%d] to another\n", _max, value);
            _wpPC.lock()->work(value);
        }
        else
        {
            printf("[%d] : I can't do [%d]\n", _max, value);
        }
    }
};

int main()
{
    std::shared_ptr<Computer> scp_10{ new SuperComputer(10) };
    std::shared_ptr<Computer> scp_20{ new SuperComputer(20) };
    std::shared_ptr<Computer> scp_50{ new SuperComputer(50) };

    scp_10->assign(scp_20);
    scp_20->assign(scp_50);

    /**
     * => [10] : I can do [5]
     * => [10] : I give [15] to another
     * => [20] : I can do [15]
     * => [10] : I give [25] to another
     * => [20] : I give [25] to another
     * => [50] : I can do [25]
     * => [10] : I give [55] to another
     * => [20] : I give [55] to another
     * => [50] : I can't do [55]
     */
    scp_10->work(5);
    scp_10->work(15);
    scp_10->work(25);
    scp_10->work(55);

    return 0;
}
