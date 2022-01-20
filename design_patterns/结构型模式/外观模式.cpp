#include <iostream>
#include <memory>

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
public:
    PhoneManufacturing() : iPhone_(std::make_shared<IPhone>()), huawei_(std::make_shared<Huawei>()) {}

    void ManufacturingIPhone() { iPhone_->manufacturing(); }
    void ManufacturingHuawei() { huawei_->manufacturing(); }

private:
    std::shared_ptr<IPhone> iPhone_;
    std::shared_ptr<Huawei> huawei_;
};

int main()
{
    std::shared_ptr<PhoneManufacturing> sp = std::make_shared<PhoneManufacturing>();

    /**
     * Manufacturing iPhone
     * Manufacturing huawei
     */
    sp->ManufacturingIPhone();
    sp->ManufacturingHuawei();

    return 0;
}
