#include <iostream>
#include <memory>
#include <string>
#include <list>
#include <algorithm>

enum OrgType
{
    Org_Type_Company = 0,
    Org_Type_Department = 1
};

class Property
{
public:
    std::string _name;
    int _type;

public:
    Property() {}

    Property(const std::string &c_name, const int c_type) : _name(c_name), _type(c_type) {}

    ~Property() {}
};

class Organization
{
private:
    Property _property;

protected:
    void assignProperty(const std::string &c_name, const OrgType c_type)
    {
        _property._name = c_name;
        _property._type = c_type;
    }

public:
    virtual ~Organization() {}

    virtual void insert(const std::shared_ptr<Organization> &c_spOrg) = 0;

    virtual void erase(const std::string &c_name, const OrgType c_type) = 0;

    virtual void display() = 0;

    virtual std::string name() const final { return _property._name; }

    virtual int type() const final { return _property._type; }
};

class Department : public Organization
{
public:
    Department(const std::string &c_name) { assignProperty(c_name, Org_Type_Company); }

    virtual ~Department() {}

    virtual void insert(const std::shared_ptr<Organization> &c_spOrg) override {}

    virtual void erase(const std::string &c_name, const OrgType type) override {}

    virtual void display() override { std::cout << "Department : " << Organization::name() << std::endl; }
};

class Company : public Organization
{
private:
    typedef std::list<std::weak_ptr<Organization>> ListOrg;
    ListOrg _lsOrg;

public:
    Company(const std::string &c_name) { assignProperty(c_name, Org_Type_Company); }
    virtual ~Company() {}

    virtual void insert(const std::shared_ptr<Organization> &c_spOrg) override
    {
        switch (c_spOrg->type())
        {
        case Org_Type_Company:
        case Org_Type_Department:
            _lsOrg.emplace_back(c_spOrg);
            break;
        default:
            break;
        }
    }

    virtual void erase(const std::string &c_name, const OrgType c_type) override
    {
        _lsOrg.erase(std::remove_if(_lsOrg.begin(), _lsOrg.end(), [&](const std::weak_ptr<Organization> &wpOrg)
                                    { return wpOrg.lock()->name() == c_name && wpOrg.lock()->type() == c_type; }),
                     _lsOrg.end());
    }

    virtual void display() override
    {
        std::cout << "Company : " << name() << std::endl;

        std::for_each(_lsOrg.begin(), _lsOrg.end(), [&](const std::weak_ptr<Organization> &wpOrg)
                      {
            std::cout << Organization::name() << " => ";
            wpOrg.lock()->display(); });
    }
};

int main()
{
    std::shared_ptr<Organization> spAlibaba{new Company{"Alibaba"}};
    std::shared_ptr<Organization> spTmall{new Company{"Tmall"}};
    std::shared_ptr<Organization> spDevelopment{new Department{"Development"}};
    std::shared_ptr<Organization> spTest{new Department{"Test"}};

    spAlibaba->insert(spTmall);
    spAlibaba->insert(spDevelopment);
    spTmall->insert(spTest);

    /**
     * => Company : Alibaba
     * => Alibaba => Company : Tmall
     * => Tmall => Department : Test
     * => Alibaba => Department : Development
     */
    spAlibaba->display();

    spTmall->erase("Test", Org_Type_Company);

    /**
     * => Company : Alibaba
     * => Alibaba => Company : Tmall
     * => Alibaba => Department : Development
     */
    spAlibaba->display();

    return 0;
}
