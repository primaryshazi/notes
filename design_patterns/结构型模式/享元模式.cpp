#include <iostream>
#include <memory>
#include <string>
#include <map>

enum PhoneType
{
    Phone_Type_None = 0,
    Phone_Type_IPhone = 1,
    Phone_Type_Huawei = 2
};

class User
{
private:
    PhoneType _phone;

public:
    User(const PhoneType c_phone) : _phone(c_phone) {}
    virtual ~User() {}

    int phone() const { return _phone; }

    virtual void buy() {}
};

class PhoneUser : public User
{
public:
    PhoneUser() : User(Phone_Type_IPhone) {}
    virtual void buy() override { std::cout << "IPhone" << std::endl; }
};

class HuawePhone : public User
{
public:
    HuawePhone() : User(Phone_Type_Huawei) {}
    virtual void buy() override { std::cout << "Huawei" << std::endl; }
};

class PhoneStore
{
private:
    std::shared_ptr<PhoneUser> _spIPhoneUser;
    std::shared_ptr<HuawePhone> _spHuaweiUser;
    std::map<std::string, PhoneType> _mapUser;

public:
    PhoneStore() : _spIPhoneUser(new PhoneUser()), _spHuaweiUser(new HuawePhone()) {}

    ~PhoneStore() {}

    void buy(const std::string &c_name, const PhoneType c_phone)
    {
        std::cout << c_name << " buy a ";
        switch (c_phone)
        {
        case Phone_Type_IPhone:
            _spIPhoneUser->buy();
            break;
        case Phone_Type_Huawei:
            _spHuaweiUser->buy();
            break;
        default:
            std::cout << "Hammer" << std::endl;
            return;
        }
        _mapUser[c_name] = c_phone;
    }

    PhoneType acquire(const std::string &c_name)
    {
        auto it = _mapUser.find(c_name);

        if (_mapUser.end() == it)
        {
            return Phone_Type_None;
        }
        else
        {
            return it->second;
        }
    }
};

int main()
{
    PhoneStore ps;

    /**
     * => father by a IPhone
     * => mather buy a Huawei
     */
    ps.buy("father", Phone_Type_IPhone);
    ps.buy("mather", Phone_Type_Huawei);

    /**
     * => 1
     * => 2
     */
    std::cout << ps.acquire("father") << std::endl;
    std::cout << ps.acquire("mather") << std::endl;

    return 0;
}
