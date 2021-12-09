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
private:
    std::string _name;

public:
    RealCountry(const std::string &c_name) : _name(c_name) {}

    virtual ~RealCountry() {}

    virtual std::string name() override { return _name; }

    virtual bool isNull() override { return true; }
};

class NullCountry : public Country
{
private:
    std::string _name;

public:
    NullCountry() : _name("nullptr") {}

    virtual ~NullCountry() {}

    virtual std::string name() override { return _name; }

    virtual bool isNull() override { return false; }
};

class CountryFactroy
{
private:
    std::list<std::string> _lsName;

public:
    CountryFactroy() : _lsName({ "China", "America" }) {}

    ~CountryFactroy() {}

    std::shared_ptr<Country> assign(const std::string &c_name)
    {
        for (const auto &c_str : _lsName)
        {
            if (c_str == c_name)
            {
                return std::make_shared<RealCountry>(c_name);
            }
        }

        return std::make_shared<NullCountry>();;
    }
};

int main()
{
    CountryFactroy cf;
    std::shared_ptr<Country> spChina = cf.assign("China");
    std::shared_ptr<Country> spAmerica = cf.assign("America");
    std::shared_ptr<Country> spNull = cf.assign("Null");

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
