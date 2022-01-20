#include <iostream>
#include <memory>
#include <string>

class Computer
{
public:
    virtual ~Computer() {}
    virtual void work() = 0;
};

class RealComputer : public Computer
{
public:
    virtual ~RealComputer() {}

    virtual void work() override
    {
        std::cout << "pi" << std::endl;
    }
};

class CloudComputer : public Computer
{
public:
    CloudComputer(const std::shared_ptr<Computer> &spPC) : wpPC_(spPC) {}

    virtual ~CloudComputer() {}

    virtual void work() override
    {
        if (wpPC_.lock())
        {
            wpPC_.lock()->work();
            std::cout << "e" << std::endl;
        }
    }

private:
    std::weak_ptr<Computer> wpPC_;
};

int main()
{
    std::shared_ptr<Computer> pRC = std::make_shared<RealComputer>();
    std::shared_ptr<Computer> pCC = std::make_shared<CloudComputer>(pRC);

    /**
     * => pi
     * => pi
     * => e
     */
    pRC->work();
    pCC->work();

    return 0;
}
