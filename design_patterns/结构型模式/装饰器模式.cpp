#include <iostream>
#include <string>

class Car
{
public:
    void drive() { std::cout << "Can drive" << std::endl; }
};

class AdvancedCar
{
protected:
    Car _car;

public:
    ~AdvancedCar() {}

    virtual void drive() = 0;
};

class Tank : public AdvancedCar
{
public:
    virtual void drive() override
    {
        _car.drive();
        std::cout << "Can fire shells" << std::endl;
    }
};

int main()
{
    Tank tank;

    /**
     * => Can drive
     * => Can fire shells
     */
    tank.drive();

    return 0;
}
