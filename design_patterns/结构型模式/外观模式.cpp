#include <iostream>

class Phone
{
public:
    virtual void manufacturing() = 0;
};

class IPhone : Phone
{
public:
    virtual void manufacturing() override { std::cout << "Manufacturing iPhone" << std::endl; }
};

class Huawei : Phone
{
public:
    virtual void manufacturing() override { std::cout << "Manufacturing huawei" << std::endl; }
};

class PhoneManufacturing
{
private:
    IPhone _iPone;
    Huawei _huawei;

public:
    void ManufacturingIPhone() { _iPone.manufacturing(); }
    void ManufacturingHuawei() { _huawei.manufacturing(); }
};

int main()
{
    PhoneManufacturing phoneMF;

    /**
     * Manufacturing iPhone
     * Manufacturing huawei
     */
    phoneMF.ManufacturingIPhone();
    phoneMF.ManufacturingHuawei();

    return 0;
}
