#include <iostream>
#include <memory>
#include <string>

class Phone
{
public:
    virtual ~Phone() {}

    virtual void Manufacturing() = 0;

    virtual std::shared_ptr<Phone> clone() = 0;
};

class Mi : public Phone
{
public:
    Mi(const std::string &name) : name_(name) {}

    virtual void Manufacturing() override
    {
        std::cout << name_ << std::endl;
    }

    virtual std::shared_ptr<Phone> clone() override
    {
        return std::make_shared<Mi>(this->name_);
    }

public:
    std::string name_;
};

int main()
{
    std::shared_ptr<Phone> spMi = std::make_shared<Mi>("Mi");
    std::shared_ptr<Phone> spBak = spMi->clone();

    /**
     * => Mi
     * => Mi
     */
    spMi->Manufacturing();
    spBak->Manufacturing();

    return 0;
}
