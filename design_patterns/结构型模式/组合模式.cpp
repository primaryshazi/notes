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
    Property() {}

    Property(const std::string &name, const int type) : name_(name), type_(type) {}

    ~Property() {}

public:
    std::string name_;
    int type_;
};

class Organization
{
protected:
    void assignProperty(const std::string &name, const OrgType type)
    {
        property_.name_ = name;
        property_.type_ = type;
    }

public:
    virtual ~Organization() {}

    virtual void insert(const std::shared_ptr<Organization> &c_spOrg) = 0;

    virtual void erase(const std::string &c_name, const OrgType c_type) = 0;

    virtual void display() = 0;

    virtual std::string name() const final { return property_.name_; }

    virtual int type() const final { return property_.type_; }

private:
    Property property_;
};

class Department : public Organization
{
public:
    Department(const std::string &name) { assignProperty(name, Org_Type_Company); }

    virtual ~Department() {}

    virtual void insert(const std::shared_ptr<Organization> &spOrg) override {}

    virtual void erase(const std::string &name, const OrgType type) override {}

    virtual void display() override { std::cout << "Department : " << Organization::name() << std::endl; }
};

class Company : public Organization
{
private:
    typedef std::list<std::weak_ptr<Organization>> ListOrg;
    ListOrg lsOrg_;

public:
    Company(const std::string &name) { assignProperty(name, Org_Type_Company); }
    virtual ~Company() {}

    virtual void insert(const std::shared_ptr<Organization> &c_spOrg) override
    {
        switch (c_spOrg->type())
        {
        case Org_Type_Company:
        case Org_Type_Department:
            lsOrg_.emplace_back(c_spOrg);
            break;
        default:
            break;
        }
    }

    virtual void erase(const std::string &name, const OrgType type) override
    {
        lsOrg_.erase(std::remove_if(lsOrg_.begin(), lsOrg_.end(), [&](const std::weak_ptr<Organization> &wpOrg)
                                    { return wpOrg.lock()->name() == name && wpOrg.lock()->type() == type; }),
                     lsOrg_.end());
    }

    virtual void display() override
    {
        std::cout << "Company : " << name() << std::endl;

        std::for_each(lsOrg_.begin(), lsOrg_.end(), [&](const std::weak_ptr<Organization> &wpOrg)
                      {
            std::cout << Organization::name() << " => ";
            wpOrg.lock()->display(); });
    }
};

int main()
{
    std::shared_ptr<Organization> spAlibaba = std::make_shared<Company>("Alibaba");
    std::shared_ptr<Organization> spTmall = std::make_shared<Company>("Tmall");
    std::shared_ptr<Organization> spDevelopment = std::make_shared<Department>("Development");
    std::shared_ptr<Organization> spTest = std::make_shared<Department>("Test");

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
