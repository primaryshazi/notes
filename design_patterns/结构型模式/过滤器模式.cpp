#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <iterator>

class Computer
{
public:
    Computer(const std::string &name, const size_t &size, const std::string &type)
        : name_(name), size_(size), type_(type) {}
    ~Computer() {}

    std::string name() const { return name_; }

    size_t size() const { return size_; }

    std::string type() const { return type_; }

    friend std::ostream &operator<<(std::ostream &os, const Computer &computer)
    {
        os << "[NAME => " << computer.name_ << "]  [SIZE => " << computer.size_
           << "]  [TYPE => " << computer.type_ << "]";

        return os;
    }

private:
    std::string name_;
    size_t size_;
    std::string type_;
};

class Standard
{
public:
    virtual std::list<Computer> acquire(const std::list<Computer> &lsPC) = 0;
};

class SizeStd : public Standard
{
public:
    SizeStd(const size_t size) : size_(size) {}

    virtual ~SizeStd() {}

    virtual std::list<Computer> acquire(const std::list<Computer> &lsPC) override
    {
        std::list<Computer> result;

        std::copy_if(lsPC.cbegin(), lsPC.cend(), std::back_inserter(result), [this](const Computer &pc)
                     { return pc.size() == this->size_; });

        return result;
    }

private:
    size_t size_;
};

class TypeStd : public Standard
{
public:
    TypeStd(const std::string &type) : type_(type) {}

    virtual ~TypeStd() {}

    virtual std::list<Computer> acquire(const std::list<Computer> &lsPC) override
    {
        std::list<Computer> result;

        std::copy_if(lsPC.cbegin(), lsPC.cend(), std::back_inserter(result), [this](const Computer &pc)
                     { return pc.type() == this->type_; });

        return result;
    }

private:
    std::string type_;
};

std::ostream &operator<<(std::ostream &os, const std::list<Computer> &lsPC)
{
    std::for_each(lsPC.cbegin(), lsPC.cend(), [&](const Computer &pc)
                  { os << pc << std::endl; });

    return os;
}

int main()
{
    std::list<Computer> lsPC{
        {"MacBook", 16, "Office"},
        {"MateBook", 14, "Office"},
        {"Lenovo", 14, "Game"}};

    SizeStd sStd(14);
    TypeStd tStd("Office");

    /**
     * SIZE STD : 14
     * [NAME => MateBook]  [SIZE => 14]  [TYPE => Office]
     * [NAME => Lenovo]  [SIZE => 14]  [TYPE => Game]
     *
     * TYPE STD : Office
     * [NAME => MacBook]  [SIZE => 16]  [TYPE => Office]
     * [NAME => MateBook]  [SIZE => 14]  [TYPE => Office]
     *
     */
    std::cout << "SIZE STD : 14" << std::endl
              << sStd.acquire(lsPC) << std::endl;
    std::cout << "TYPE STD : Office" << std::endl
              << tStd.acquire(lsPC) << std::endl;

    return 0;
}
