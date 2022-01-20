#include <iostream>
#include <memory>
#include <string>

class Computer
{
protected:
    Computer() : max_(0) {}

public:
    virtual ~Computer() {}

    virtual void assign(const std::shared_ptr<Computer> &c_spPC) = 0;

    virtual void work(int value) = 0;

protected:
    int max_;
    std::weak_ptr<Computer> wpPC_;
};

class SuperComputer : public Computer
{
public:
    SuperComputer(const int max) : Computer() { max_ = max; }

    virtual ~SuperComputer() {}

    virtual void assign(const std::shared_ptr<Computer> &spPC) override { wpPC_ = spPC; }

    virtual void work(int value) override
    {
        if (value <= max_)
        {
            printf("[%d] : I can do [%d]\n", max_, value);
        }
        else if (!wpPC_.expired() && wpPC_.lock())
        {
            printf("[%d] : I give [%d] to another\n", max_, value);
            wpPC_.lock()->work(value);
        }
        else
        {
            printf("[%d] : I can't do [%d]\n", max_, value);
        }
    }
};

int main()
{
    std::shared_ptr<Computer> scp_10 = std::make_shared<SuperComputer>(10);
    std::shared_ptr<Computer> scp_20 = std::make_shared<SuperComputer>(20);
    std::shared_ptr<Computer> scp_50 = std::make_shared<SuperComputer>(50);

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
