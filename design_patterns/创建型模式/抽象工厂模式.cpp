#include <iostream>
#include <memory>
#include <string>

class Car
{
public:
    virtual void manufacturing() = 0;
};

class Benz : public Car
{
public:
    void manufacturing() override
    {
        std::cout << "Manufacturing Benz" << std::endl;
    }
};

class BMW : public Car
{
public:
    void manufacturing() override
    {
        std::cout << "Manufacturing BMW" << std::endl;
    }
};

class Airplane
{
public:
    virtual void manufacturing() = 0;
};

class Boeing : public Airplane
{
public:
    void manufacturing() override
    {
        std::cout << "Manufacturing Boeing" << std::endl;
    }
};

class Airbus : public Airplane
{
public:
    void manufacturing() override
    {
        std::cout << "Manufacturing Airbus" << std::endl;
    }
};

class AbstractFactory
{
public:
    virtual std::shared_ptr<Car> getCar(const std::string &carType) = 0;

    virtual std::shared_ptr<Airplane> getAirplane(const std::string &airplaneType) = 0;
};

class CarFactory : public AbstractFactory
{
public:
    virtual std::shared_ptr<Car> getCar(const std::string &carType) override
    {
        if (carType == "Benz")
        {
            return std::make_shared<Benz>();
        }
        else if (carType == "BMW")
        {
            return std::make_shared<BMW>();
        }
        else
        {
            return nullptr;
        }
    }

    virtual std::shared_ptr<Airplane> getAirplane(const std::string &airplaneType) override { return nullptr; }
};

class AirplaneFactory : public AbstractFactory
{
public:
    virtual std::shared_ptr<Car> getCar(const std::string &carType) override { return nullptr; }

    virtual std::shared_ptr<Airplane> getAirplane(const std::string &airplaneType) override
    {
        if (airplaneType == "Boeing")
        {
            return std::make_shared<Boeing>();
        }
        else if (airplaneType == "Airbus")
        {
            return std::make_shared<Airbus>();
        }
        else
        {
            return nullptr;
        }
    }
};

class ProduceFactory
{
public:
    std::shared_ptr<AbstractFactory> getFactory(const std::string &factoryType)
    {
        if (factoryType == "Car")
        {
            return std::make_shared<CarFactory>();
        }
        else if (factoryType == "Airplane")
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
    ProduceFactory factory;

    std::shared_ptr<AbstractFactory> spCarFactory = factory.getFactory("Car");
    std::shared_ptr<AbstractFactory> spAirplaneFactory = factory.getFactory("Airplane");

    std::shared_ptr<Car> spBenz = spCarFactory->getCar("Benz");
    std::shared_ptr<Car> spBMW = spCarFactory->getCar("BMW");
    std::shared_ptr<Airplane> spBoeing = spAirplaneFactory->getAirplane("Boeing");
    std::shared_ptr<Airplane> spAirbus = spAirplaneFactory->getAirplane("Airbus");

    /**
     * => Manufacturing Benz
     * => Manufacturing BMW
     * => Manufacturing Boeing
     * => Manufacturing Airbus
     */
    spBenz->manufacturing();
    spBMW->manufacturing();
    spBoeing->manufacturing();
    spAirbus->manufacturing();

    return 0;
}
