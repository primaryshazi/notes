#include <iostream>
#include <string>
#include <memory>

class Phone
{
protected:
    std::string _name;

public:
    virtual void assignName(const std::string &c_name) final { _name = c_name; }

    virtual void manufacturing() {}
};

class Huawei : public Phone
{
public:
    virtual void manufacturing() override
    {
        std::cout << "manufacturing " << _name << std::endl;
    }
};

class Mi : public Phone
{
public:
    virtual void manufacturing() override
    {
        std::cout << "manufacturing " << _name << std::endl;
    }
};

class ManufacturingPhone
{
private:
    std::weak_ptr<Phone> _wpPhone;

public:
    ManufacturingPhone(const std::shared_ptr<Phone> &c_spPhone) : _wpPhone(c_spPhone) {}

    void manufacturing(const std::string &c_name)
    {
        if (!_wpPhone.expired() && _wpPhone.lock())
        {
            _wpPhone.lock()->assignName(c_name);
            _wpPhone.lock()->manufacturing();
        }
    }
};

int main()
{
    std::shared_ptr<Mi> spMi{ new Mi() };
    std::shared_ptr<Huawei> spHuawei{ new Huawei() };
    ManufacturingPhone manufacturingMI{ spMi };
    ManufacturingPhone manufacturingHuawei{ spHuawei };

    /**
     * manufacturing Mi
     * manufacturing Huawei
     */
    manufacturingMI.manufacturing("Mi");
    manufacturingHuawei.manufacturing("Huawei");

    return 0;
}
