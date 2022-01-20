#include <iostream>
#include <memory>
#include <string>
#include <list>

class Country
{
public:
    virtual ~Country() {}

    virtual std::string name() = 0;

    virtual bool isNull() = 0;
};

class RealCountry : public Country
{
public:
    RealCountry(const std::string &name) : name_(name) {}

    virtual ~RealCountry() {}

    virtual std::string name() override { return name_; }

    virtual bool isNull() override { return true; }

private:
    std::string name_;
};

class NullCountry : public Country
{
public:
    NullCountry() : name_("nullptr") {}

    virtual ~NullCountry() {}

    virtual std::string name() override { return name_; }

    virtual bool isNull() override { return false; }

private:
    std::string name_;
};

class CountryFactory
{
public:
    CountryFactory() : lsName_({"China", "America"}) {}

    ~CountryFactory() {}

    std::shared_ptr<Country> assign(const std::string &c_name)
    {
        for (const auto &c_str : lsName_)
        {
            if (c_str == c_name)
            {
                return std::make_shared<RealCountry>(c_name);
            }
        }

        return std::make_shared<NullCountry>();
        ;
    }

private:
    std::list<std::string> lsName_;
};

int main()
{
    std::shared_ptr<CountryFactory> spFactory = std::make_shared<CountryFactory>();
    std::shared_ptr<Country> spChina = spFactory->assign("China");
    std::shared_ptr<Country> spAmerica = spFactory->assign("America");
    std::shared_ptr<Country> spNull = spFactory->assign("Null");

    /**
     * => China
     * => America
     * => nullptr
     */
    std::cout << spChina->name() << std::endl;
    std::cout << spAmerica->name() << std::endl;
    std::cout << spNull->name() << std::endl;

    return 0;
}
