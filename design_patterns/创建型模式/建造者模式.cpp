#include <iostream>
#include <string>
#include <memory>

class Phone
{
public:
    virtual void assignName(const std::string &name) final { name_ = name; }

    virtual void manufacturing() {}

protected:
    std::string name_;
};

class Huawei : public Phone
{
public:
    virtual void manufacturing() override
    {
        std::cout << "manufacturing " << name_ << std::endl;
    }
};

class Mi : public Phone
{
public:
    virtual void manufacturing() override
    {
        std::cout << "manufacturing " << name_ << std::endl;
    }
};

class ManufacturingPhone
{
public:
    ManufacturingPhone(const std::shared_ptr<Phone> &spPhone) : wpPhone_(spPhone) {}

    void manufacturing(const std::string &name)
    {
        if (!wpPhone_.expired() && wpPhone_.lock())
        {
            wpPhone_.lock()->assignName(name);
            wpPhone_.lock()->manufacturing();
        }
    }

private:
    std::weak_ptr<Phone> wpPhone_;
};

int main()
{
    std::shared_ptr<Mi> spMi = std::shared_ptr<Mi>();
    std::shared_ptr<Huawei> spHuawei = std::shared_ptr<Huawei>();
    ManufacturingPhone manufacturingMI{spMi};
    ManufacturingPhone manufacturingHuawei{spHuawei};

    /**
     * manufacturing Mi
     * manufacturing Huawei
     */
    manufacturingMI.manufacturing("Mi");
    manufacturingHuawei.manufacturing("Huawei");

    return 0;
}
