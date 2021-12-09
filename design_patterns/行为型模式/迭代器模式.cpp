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
private:
    std::weak_ptr<Aggregate> _wpAgt;
    size_t _index;

public:
    RealIter(const std::shared_ptr<Aggregate> &c_spAgt) : _wpAgt(c_spAgt), _index(0) {}

    virtual ~RealIter() {}

    virtual void first() override
    {
        _index = 0;
    }
    virtual void next() override
    {
        _index++;
    }
    virtual int &current() override
    {
        return (*_wpAgt.lock())[_index];
    }
    virtual bool isEnd() override
    {
        return _index >= _wpAgt.lock()->size();
    }
};

class RealAggregate : public std::enable_shared_from_this<RealAggregate>, public Aggregate
{
private:
    std::vector<int> _vecInt;

public:
    RealAggregate() {}

    virtual ~RealAggregate() {}

    virtual void push(int value) override
    {
        _vecInt.emplace_back(value);
    }

    virtual std::shared_ptr<Iter> create() override
    {
        return std::make_shared<RealIter>(shared_from_this());
    }

    virtual size_t size() override
    {
        return _vecInt.size();
    }

    virtual int &operator[](int index) override
    {
        return _vecInt[index];
    }
};

int main()
{
    std::shared_ptr<Aggregate> spAgt{ new RealAggregate{} };

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
