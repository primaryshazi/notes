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
private:
    std::weak_ptr<Computer> _wpPC;

public:
    CloudComputer(const std::shared_ptr<Computer> &c_spPC) : _wpPC(c_spPC) {}

    virtual ~CloudComputer() {}

    virtual void work() override
    {
        if (_wpPC.lock())
        {
            _wpPC.lock()->work();
            std::cout << "e" << std::endl;
        }
    }
};

int main()
{
    std::shared_ptr<Computer> pRC{ new RealComputer{} };
    std::shared_ptr<Computer> pCC{ new CloudComputer{pRC} };

    /**
     * => pi
     * => pi
     * => e
     */
    pRC->work();
    pCC->work();

    return 0;
}
