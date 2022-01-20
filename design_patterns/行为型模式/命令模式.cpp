#include <iostream>
#include <memory>
#include <list>
#include <functional>

typedef std::function<void()> SimpleTask;

class Command
{
public:
    virtual ~Command() {}

    virtual void exec() = 0;

protected:
    SimpleTask task_;
};

class RealCmd : public Command
{
public:
    RealCmd(const SimpleTask &task) { task_ = task; }

    virtual ~RealCmd() {}

    virtual void exec() override { task_(); }
};

class User
{
public:
    void insert(const std::weak_ptr<Command> &spCmd) { lsCmd_.emplace_back(spCmd); }

    void clear() { lsCmd_.clear(); }

    void exec() const
    {
        for (const auto &wp : lsCmd_)
        {
            wp.lock()->exec();
        }
    }

private:
    std::list<std::weak_ptr<Command>> lsCmd_;
};

int main()
{
    std::shared_ptr<User> spRoot = std::make_shared<User>();
    std::shared_ptr<Command> spHelloWorld = std::make_shared<RealCmd>([]()
                                                                      { std::cout << "Hello World!" << std::endl; });
    std::shared_ptr<Command> spAreYouOK = std::make_shared<RealCmd>([]()
                                                                    { std::cout << "Are you OK?" << std::endl; });

    spRoot->insert(spHelloWorld);
    spRoot->insert(spAreYouOK);

    /**
     * => Hello World!
     * => Are you OK?
     */
    spRoot->exec();
    spRoot->clear();

    return 0;
}
