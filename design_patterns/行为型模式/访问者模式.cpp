#include <iostream>
#include <memory>
#include <string>
#include <list>

class Visitor;

class Mountain
{
public:
    virtual ~Mountain() {}

    virtual void accept(const std::shared_ptr<Visitor> &spVisitor) = 0;

    virtual std::string name() final { return name_; }

protected:
    std::string name_;
};

class Visitor
{
public:
    void visit(const std::shared_ptr<Mountain> &spMountain) { std::cout << "View " << spMountain->name() << std::endl; }

    virtual ~Visitor() {}
};

class MountTai : public Mountain, public std::enable_shared_from_this<MountTai>
{
public:
    MountTai(const std::string &name) { name_ = name; }

    virtual ~MountTai() {}

    virtual void accept(const std::shared_ptr<Visitor> &spVisitor) override { spVisitor->visit(shared_from_this()); }
};

class MountHua : public Mountain, public std::enable_shared_from_this<MountHua>
{
public:
    MountHua(const std::string &name) { name_ = name; }

    virtual ~MountHua() {}

    virtual void accept(const std::shared_ptr<Visitor> &spVisitor) override { spVisitor->visit(shared_from_this()); }
};

class FamousMountain : public Mountain
{
public:
    FamousMountain() : lsMtn_({std::make_shared<MountTai>("Hua Shan"), std::make_shared<MountHua>("Tai Shan")}) {}

    virtual ~FamousMountain() {}

    virtual void accept(const std::shared_ptr<Visitor> &spVisitor) override
    {
        for (auto spMtn : lsMtn_)
        {
            if (nullptr != spMtn)
            {
                spMtn->accept(spVisitor);
            }
        }
    }

private:
    std::list<std::shared_ptr<Mountain>> lsMtn_;
};

int main()
{
    std::shared_ptr<Visitor> spVisitor = std::make_shared<Visitor>();
    std::shared_ptr<Mountain> spFm = std::make_shared<FamousMountain>();

    /**
     * => View Tai Shan
     * => View Hua Shan
     */
    spFm->accept(spVisitor);

    return 0;
}
