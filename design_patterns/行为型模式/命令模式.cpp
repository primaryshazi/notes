#include <iostream>
#include <memory>
#include <string>
#include <list>
#include <functional>
#include <algorithm>

typedef std::function<void()> Task;

class Command
{
protected:
    Task _task;

public:
    virtual ~Command() {}

    virtual void exec() = 0;
};

class RealCmd : public Command
{
public:
    RealCmd(Task task) { _task = task; }

    virtual ~RealCmd() {}

    virtual void exec() override { _task(); }
};

class User
{
private:
    std::list<std::weak_ptr<Command>> _lsCmd;

public:
    void insert(const std::weak_ptr<Command> &c_spCmd) { _lsCmd.emplace_back(c_spCmd); }

    void clear() { _lsCmd.clear(); }

    void exec() const
    {
        for (const auto &wp : _lsCmd)
        {
            wp.lock()->exec();
        }
    }
};

int main()
{
    User root;
    std::shared_ptr<Command> spHelloWorld{ new RealCmd{[]() { std::cout << "Hello World!" << std::endl; } } };
    std::shared_ptr<Command> spAreYouOK{ new RealCmd{[]() { std::cout << "Are you OK?" << std::endl; } } };

    root.insert(spHelloWorld);
    root.insert(spAreYouOK);

    /**
     * => Hello World!
     * => Are you OK?
     */
    root.exec();
    root.clear();

    return 0;
}
