#include <iostream>
#include <memory>
#include <string>
#include <list>

class Visitor;

class Mountain
{
public:
    virtual ~Mountain() {}

    virtual void accept(const std::shared_ptr<Visitor> &c_spVisitor) = 0;

    virtual std::string name() final { return _name; }

protected:
    std::string _name;
};

class Visitor
{
public:
    void visit(const std::shared_ptr<Mountain> &c_spMountain) { std::cout << "View " << c_spMountain->name() << std::endl; }

    virtual ~Visitor() {}
};

class MountTai : public Mountain, public std::enable_shared_from_this<MountTai>
{
public:
    MountTai(const std::string &name) { _name = name; }

    virtual ~MountTai() {}

    virtual void accept(const std::shared_ptr<Visitor> &c_spVisitor) override { c_spVisitor->visit(shared_from_this()); }
};

class MountHua : public Mountain, public std::enable_shared_from_this<MountHua>
{
public:
    MountHua(const std::string &name) { _name = name; }

    virtual ~MountHua() {}

    virtual void accept(const std::shared_ptr<Visitor> &c_spVisitor) override { c_spVisitor->visit(shared_from_this()); }
};

class FamousMountain : public Mountain
{
public:
    FamousMountain() : _lsMtn({std::make_shared<MountTai>("Hua Shan"), std::make_shared<MountHua>("Tai Shan")}) {}

    virtual ~FamousMountain() {}

    virtual void accept(const std::shared_ptr<Visitor> &spVisitor) override
    {
        for (auto spMtn : _lsMtn)
        {
            if (nullptr != spMtn)
            {
                spMtn->accept(spVisitor);
            }
        }
    }

private:
    std::list<std::shared_ptr<Mountain>> _lsMtn;
};

int main()
{
    std::shared_ptr<Visitor> spVisitor{new Visitor{}};
    std::shared_ptr<Mountain> spFm{new FamousMountain{}};

    /**
     * => View Tai Shan
     * => View Hua Shan
     */
    spFm->accept(spVisitor);

    return 0;
}
