#include <iostream>
#include <memory>
#include <string>

class Person
{
public:
    virtual ~Person() {}

    virtual std::string name() = 0;

    virtual void say(const std::string &message) = 0;
};

class Behavior
{
public:
    static void say(const std::shared_ptr<Person> &spPerson, const std::string &message)
    {
        std::cout << spPerson->name() << " : " << message << std::endl;
    }
};

class Soldier : public Person, public std::enable_shared_from_this<Soldier>
{
public:
    Soldier(const std::string &name) : name_(name) {}

    virtual ~Soldier() {}

    virtual void say(const std::string &message) { Behavior::say(shared_from_this(), message); }

    virtual std::string name() override { return name_; }

private:
    std::string name_;
};

int main()
{
    std::shared_ptr<Person> spSoldier = std::make_shared<Soldier>("Soldier");

    /**
     * => Soldier : Defend my country
     */
    spSoldier->say("Defend my country");

    return 0;
}
