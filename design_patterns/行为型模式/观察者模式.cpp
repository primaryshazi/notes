#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

class ObserverInterface
{
public:
    virtual void exec() = 0;
    virtual ~ObserverInterface() {}
};

class SubjectInterface
{
public:
    virtual void insert(const std::shared_ptr<ObserverInterface> &spObr) = 0;
    virtual void notify() = 0;

    virtual ~SubjectInterface() {}
};

class ObserverOne : public ObserverInterface
{
public:
    virtual void exec() override
    {
        std::cout << "one exec" << std::endl;
    }

    virtual ~ObserverOne() {}
};

class ObserverTwo : public ObserverInterface
{
public:
    virtual void exec() override
    {
        std::cout << "two exec" << std::endl;
    }

    virtual ~ObserverTwo() {}
};

class Subject : public SubjectInterface
{
public:
    virtual void insert(const std::shared_ptr<ObserverInterface> &spObr) override
    {
        _vObrs.emplace_back(spObr);
    }

    virtual void notify() override
    {
        std::for_each(_vObrs.begin(), _vObrs.end(), [&](const std::weak_ptr<ObserverInterface> &wpObr)
                      { wpObr.lock()->exec(); });
    }

    virtual ~Subject() {}

private:
    std::vector<std::weak_ptr<ObserverInterface>> _vObrs;
};

int main()
{
    std::shared_ptr<SubjectInterface> spSub = std::make_shared<Subject>();
    std::shared_ptr<ObserverInterface> spObrOne = std::make_shared<ObserverOne>();
    std::shared_ptr<ObserverInterface> spObrTwo = std::make_shared<ObserverTwo>();

    spSub->insert(spObrOne);
    spSub->insert(spObrTwo);

    /**
     * => one exec
     * => two exec
     */
    spSub->notify();

    return 0;
}
