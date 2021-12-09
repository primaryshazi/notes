#include <iostream>
#include <memory>
#include <string>

class Status;

class Behavior
{
protected:
    std::weak_ptr<Status> _wpStatus;

public:
    Behavior() {}

    ~Behavior() {}

    void assign(const std::weak_ptr<Status> &c_spStatus) { _wpStatus = c_spStatus; }

    std::shared_ptr<Status> acquire() { return _wpStatus.lock(); }
};

class Status : public std::enable_shared_from_this<Status>
{
protected:
    std::string _status;
    std::weak_ptr<Behavior> _wpBhr;

protected:
    Status() {}

public:
    virtual ~Status() {}

    virtual void work(const std::shared_ptr<Behavior> &c_spBhr) final { c_spBhr->assign(shared_from_this()); }

    virtual std::string current() final { return _status; }
};

class RunStatus : public Status
{
public:
    RunStatus() { _status = "RUN"; }

    virtual ~RunStatus() {}
};

class WalkStatus : public Status
{
public:
    WalkStatus() { _status = "WALK"; }

    virtual ~WalkStatus() {}
};

int main()
{
    std::shared_ptr<Behavior> spBehavior{ new Behavior{} };

    std::shared_ptr<Status> spRun{ new RunStatus{} };
    std::shared_ptr<Status> spWalk{ new WalkStatus{} };

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
