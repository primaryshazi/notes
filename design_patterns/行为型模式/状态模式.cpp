#include <iostream>
#include <memory>
#include <string>

class Status;

class Behavior
{
public:
    Behavior() {}

    ~Behavior() {}

    void assign(const std::weak_ptr<Status> &spStatus) { spStatus_ = spStatus; }

    std::shared_ptr<Status> acquire() { return spStatus_.lock(); }

protected:
    std::weak_ptr<Status> spStatus_;
};

class Status : public std::enable_shared_from_this<Status>
{
protected:
    Status() {}

public:
    virtual ~Status() {}

    virtual void work(const std::shared_ptr<Behavior> &spBhr) final { spBhr->assign(shared_from_this()); }

    virtual std::string current() final { return status_; }

protected:
    std::string status_;
    std::weak_ptr<Behavior> wpBhr_;
};

class RunStatus : public Status
{
public:
    RunStatus() { status_ = "RUN"; }

    virtual ~RunStatus() {}
};

class WalkStatus : public Status
{
public:
    WalkStatus() { status_ = "WALK"; }

    virtual ~WalkStatus() {}
};

int main()
{
    std::shared_ptr<Behavior> spBehavior = std::make_shared<Behavior>();
    std::shared_ptr<Status> spRun = std::make_shared<RunStatus>();
    std::shared_ptr<Status> spWalk = std::make_shared<WalkStatus>();

    /**
     * => RUN
     * => WALK
     */
    spRun->work(spBehavior);
    std::cout << spBehavior->acquire()->current() << std::endl;
    spWalk->work(spBehavior);
    std::cout << spBehavior->acquire()->current() << std::endl;

    return 0;
}
