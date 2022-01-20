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
public:
    Adapter() : spCar_(std::make_shared<Car>()), spAirplane_(std::make_shared<Airplane>()) {}

    ~Adapter() {}

    void make(const std::string &type)
    {
        if (type == "Car")
        {
            spCar_->manufacturing();
        }
        else if (type == "Airplane")
        {
            spAirplane_->manufacturing();
        }
        else
        {
            std::cout << "error" << std::endl;
        }
    }

private:
    std::shared_ptr<Car> spCar_;
    std::shared_ptr<Airplane> spAirplane_;
};

int main()
{
    std::shared_ptr<Adapter> sp = std::make_shared<Adapter>();

    /**
     * => Manufacturing Car
     * => Manufacturing Airplane
     */
    sp->make("Car");
    sp->make("Airplane");

    return 0;
}
