#include <iostream>
#include <memory>
#include <string>

class Car
{
public:
    void manufacturing()
    {
        std::cout << "Manufacturing Car" << std::endl;
    }
};

class Airplane
{
public:
    void manufacturing()
    {
        std::cout << "Manufacturing Airplane" << std::endl;
    }
};

class Adapter
{
private:
    std::shared_ptr<Car> spCar;
    std::shared_ptr<Airplane> spAirplane;

public:
    Adapter() : spCar(new Car{}), spAirplane(new Airplane{}) {}

    ~Adapter() {}

    void make(const std::string &type)
    {
        if (type == "Car")
        {
            spCar->manufacturing();
        }
        else if (type == "Airplane")
        {
            spAirplane->manufacturing();
        }
        else
        {
            std::cout << "error" << std::endl;
        }
    }
};

int main()
{
    Adapter adapter;

    /**
     * => Manufacturing Car
     * => Manufacturing Airplane
     */
    adapter.make("Car");
    adapter.make("Airplane");

    return 0;
}
