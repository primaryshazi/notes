#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>

class Status
{
private:
    std::string _status;

public:
    Status(const std::string &c_st) : _status(c_st) {}

    ~Status() {}

    std::string acquire() const { return _status; }
};

class Browse
{
private:
    std::string _currentStats;

public:
    void assign(const std::string &c_st) { _currentStats = c_st; }

    std::string acquire() const { return _currentStats; }

    std::shared_ptr<Status> save() { return std::make_shared<Status>(_currentStats); }
};

class Record
{
private:
    std::vector<std::shared_ptr<Status>> _vecStatus;

public:
    void insert(const std::shared_ptr<Status> &c_spStatus) { _vecStatus.emplace_back(c_spStatus); }

    std::shared_ptr<Status> indexOf(size_t index) { return _vecStatus.at(index); }
};

int main()
{
    Browse browse;
    Record record;

    browse.assign("A");
    record.insert(browse.save());

    browse.assign("B");
    record.insert(browse.save());

    browse.assign("C");
    record.insert(browse.save());

    /**
     * => A
     * => B
     * => C
     */
    std::cout << record.indexOf(0)->acquire() << std::endl;
    std::cout << record.indexOf(1)->acquire() << std::endl;
    std::cout << record.indexOf(2)->acquire() << std::endl;

    return 0;
}
