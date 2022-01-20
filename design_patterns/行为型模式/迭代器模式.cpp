#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <iterator>

class Iter
{
public:
    virtual ~Iter() {}
    virtual void first() = 0;
    virtual void next() = 0;
    virtual int &current() = 0;
    virtual bool isEnd() = 0;
};

class Aggregate
{
public:
    virtual ~Aggregate() {}

    virtual void push(int value) = 0;

    virtual std::shared_ptr<Iter> create() = 0;

    virtual size_t size() = 0;

    virtual int &operator[](int index) = 0;
};

class RealIter : public Iter
{
public:
    RealIter(const std::shared_ptr<Aggregate> &c_spAgt) : wpAgt_(c_spAgt), index_(0) {}

    virtual ~RealIter() {}

    virtual void first() override
    {
        index_ = 0;
    }
    virtual void next() override
    {
        index_++;
    }
    virtual int &current() override
    {
        return (*wpAgt_.lock())[index_];
    }
    virtual bool isEnd() override
    {
        return index_ >= wpAgt_.lock()->size();
    }

private:
    std::weak_ptr<Aggregate> wpAgt_;
    size_t index_;
};

class RealAggregate : public std::enable_shared_from_this<RealAggregate>, public Aggregate
{
public:
    RealAggregate() {}

    virtual ~RealAggregate() {}

    virtual void push(int value) override
    {
        vElement_.emplace_back(value);
    }

    virtual std::shared_ptr<Iter> create() override
    {
        return std::make_shared<RealIter>(shared_from_this());
    }

    virtual size_t size() override
    {
        return vElement_.size();
    }

    virtual int &operator[](int index) override
    {
        return vElement_[index];
    }

private:
    std::vector<int> vElement_;
};

int main()
{
    std::shared_ptr<Aggregate> spAgt = std::make_shared<RealAggregate>();

    for (int i = 0; i < 5; i++)
    {
        spAgt->push(i);
    }

    std::shared_ptr<Iter> it = spAgt->create();
    it->first();

    /**
     * => 0
     * => 1
     * => 2
     * => 3
     * => 4
     */
    while (!it->isEnd())
    {
        std::cout << it->current() << std::endl;
        it->next();
    }

    return 0;
}
