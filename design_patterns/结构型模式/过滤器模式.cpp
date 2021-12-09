#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <iterator>

class Computer
{
private:
    std::string _name;
    size_t _size;
    std::string _type;

public:
    Computer(const std::string &c_name, const size_t &c_size, const std::string &c_type)
        : _name(c_name), _size(c_size), _type(c_type) {}
    ~Computer() {}

    std::string name() const { return _name; }

    size_t size() const { return _size; }

    std::string type() const { return _type; }

    friend std::ostream &operator<<(std::ostream &os, const Computer &c_computer)
    {
        os << "[NAME => " << c_computer._name << "]  [SIZE => " << c_computer._size
            << "]  [TYPE => " << c_computer._type << "]";

        return os;
    }
};

class Standard
{
public:
    virtual std::list<Computer> acquire(const std::list<Computer> &c_lsPC) = 0;
};

class SizeStd : public Standard
{
private:
    size_t _size;

public:
    SizeStd(const size_t c_size) : _size(c_size) {}

    virtual ~SizeStd() {}

    virtual std::list<Computer> acquire(const std::list<Computer> &c_lsPC) override
    {
        std::list<Computer> lsPC;

        std::copy_if(c_lsPC.cbegin(), c_lsPC.cend(), std::back_inserter(lsPC), [this](const Computer &c_PC) {
            return c_PC.size() == this->_size;
            });

        return lsPC;
    }
};

class TypeStd : public Standard
{
private:
    std::string _type;

public:
    TypeStd(const std::string &c_type) : _type(c_type) {}
    virtual ~TypeStd() {}

    virtual std::list<Computer> acquire(const std::list<Computer> &c_lsPC) override
    {
        std::list<Computer> lsPC;

        std::copy_if(c_lsPC.cbegin(), c_lsPC.cend(), std::back_inserter(lsPC), [this](const Computer &c_PC) {
            return c_PC.type() == this->_type;
            });

        return lsPC;
    }
};

std::ostream &operator<<(std::ostream &os, const std::list<Computer> &c_lsPC)
{
    std::for_each(c_lsPC.cbegin(), c_lsPC.cend(), [&](const Computer &c_PC) {
        os << c_PC << std::endl;
        });

    return os;
}

int main()
{
    std::list<Computer> lsPC{
        {"MacBook", 16, "Office"},
        {"MateBook", 14, "Office"},
        {"Lenovo", 14, "Game"} };

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
