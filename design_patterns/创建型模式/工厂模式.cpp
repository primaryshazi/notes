#include <iostream>
#include <memory>
#include <string>

class Factory
{
public:
    virtual void manufacturing() = 0;
};

class CarFactory : public Factory
{
    virtual void manufacturing() override
    {
        std::cout << "manufacturing Car" << std::endl;
    }
};

class AirplaneFactory : public Factory
{
    virtual void manufacturing() override
    {
        std::cout << "manufacturing Airplane" << std::endl;
    }
};

class ProduceFactory
{
public:
    std::shared_ptr<Factory> GetFactory(const std::string &type)
    {
        if (type == "Car")
        {
            return std::make_shared<CarFactory>();
        }
        else if (type == "Airplane")
        {
            return std::make_shared<AirplaneFactory>();
        }
        else
        {
            return nullptr;
        }
    }
};

int main()
{
    ProduceFactory produce;

    std::shared_ptr<Factory> spCarFactory = produce.GetFactory("Car");
    std::shared_ptr<Factory> spAirplaneFactory = produce.GetFactory("Airplane");

    /**
     * => manufacturing Car
     * => manufacturing Airplane
     */
    spCarFactory->manufacturing();
    spAirplaneFactory->manufacturing();

    return 0;
}
