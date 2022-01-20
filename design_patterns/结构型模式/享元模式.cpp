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
    PhoneType phone_;

public:
    User(const PhoneType phone) : phone_(phone) {}
    virtual ~User() {}

    int phone() const { return phone_; }

    virtual void buy() {}
};

class IPhoneUser : public User
{
public:
    IPhoneUser() : User(Phone_Type_IPhone) {}
    virtual void buy() override { std::cout << "IPhone" << std::endl; }
};

class HuaweiPhone : public User
{
public:
    HuaweiPhone() : User(Phone_Type_Huawei) {}
    virtual void buy() override { std::cout << "Huawei" << std::endl; }
};

class PhoneStore
{
private:
    std::shared_ptr<IPhoneUser> spIPhoneUser_;
    std::shared_ptr<HuaweiPhone> spHuaweiUser_;
    std::map<std::string, PhoneType> mapUser_;

public:
    PhoneStore() : spIPhoneUser_(new IPhoneUser()), spHuaweiUser_(new HuaweiPhone()) {}

    ~PhoneStore() {}

    void buy(const std::string &name, const PhoneType phone)
    {
        std::cout << name << " buy a ";
        switch (phone)
        {
        case Phone_Type_IPhone:
            spIPhoneUser_->buy();
            break;
        case Phone_Type_Huawei:
            spHuaweiUser_->buy();
            break;
        default:
            std::cout << "Hammer" << std::endl;
            return;
        }
        mapUser_[name] = phone;
    }

    PhoneType acquire(const std::string &name)
    {
        auto it = mapUser_.find(name);

        if (mapUser_.end() == it)
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
    std::shared_ptr<PhoneStore> sp = std::make_shared<PhoneStore>();

    /**
     * => father by a IPhone
     * => mather buy a Huawei
     */
    sp->buy("father", Phone_Type_IPhone);
    sp->buy("mather", Phone_Type_Huawei);

    /**
     * => 1
     * => 2
     */
    std::cout << sp->acquire("father") << std::endl;
    std::cout << sp->acquire("mather") << std::endl;

    return 0;
}
