#include <iostream>
#include <memory>

class Car
{
public:
    void drive() { std::cout << "Can drive" << std::endl; }
};

class AdvancedCar
{
public:
    AdvancedCar() : spCar_(std::make_shared<Car>()) {}

    ~AdvancedCar() {}

    virtual void drive() = 0;

protected:
    std::shared_ptr<Car> spCar_;
};

class Tank : public AdvancedCar
{
public:
    virtual void drive() override
    {
        spCar_->drive();
        std::cout << "Can fire shells" << std::endl;
    }
};

int main()
{
    std::shared_ptr<Tank> sp = std::make_shared<Tank>();

    /**
     * => Can drive
     * => Can fire shells
     */
    sp->drive();

    return 0;
}
