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
    std::string _name;

public:
    Mi(const std::string &c_name) : _name(c_name) {}

    virtual void Manufacturing() override
    {
        std::cout << _name << std::endl;
    }

    virtual std::shared_ptr<Phone> clone() override
    {
        return std::make_shared<Mi>(*this);
    }
};

int main()
{
    std::shared_ptr<Phone> spMi{ new Mi{"Mi"} };
    std::shared_ptr<Phone> spBak = spMi->clone();

    /**
     * => Mi
     * => Mi
     */
    spMi->Manufacturing();
    spBak->Manufacturing();

    return 0;
}
