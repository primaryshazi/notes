#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>

class Status
{
public:
    Status(const std::string &c_st) : status_(c_st) {}

    ~Status() {}

    std::string acquire() const { return status_; }

private:
    std::string status_;
};

class Browse
{
public:
    void assign(const std::string &c_st) { curStatus_ = c_st; }

    std::string acquire() const { return curStatus_; }

    std::shared_ptr<Status> save() { return std::make_shared<Status>(curStatus_); }

private:
    std::string curStatus_;
};

class Record
{
public:
    void insert(const std::shared_ptr<Status> &c_spStatus) { vStatus_.emplace_back(c_spStatus); }

    std::shared_ptr<Status> indexOf(size_t index) { return vStatus_.at(index); }

private:
    std::vector<std::shared_ptr<Status>> vStatus_;
};

int main()
{
    std::shared_ptr<Browse> spBrowse = std::make_shared<Browse>();
    std::shared_ptr<Record> spRecord = std::make_shared<Record>();

    spBrowse->assign("A");
    spRecord->insert(spBrowse->save());

    spBrowse->assign("B");
    spRecord->insert(spBrowse->save());

    spBrowse->assign("C");
    spRecord->insert(spBrowse->save());

    /**
     * => A
     * => B
     * => C
     */
    std::cout << spRecord->indexOf(0)->acquire() << std::endl;
    std::cout << spRecord->indexOf(1)->acquire() << std::endl;
    std::cout << spRecord->indexOf(2)->acquire() << std::endl;

    return 0;
}
