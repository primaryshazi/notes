#include <iostream>
#include <memory>
#include <string>

class Person
{
public:
    virtual ~Person() {}

    virtual std::string name() = 0;

    virtual void say(const std::string &c_msg) = 0;
};

class Behavior
{
public:
    static void say(const std::shared_ptr<Person> &c_spPsn, const std::string &c_msg)
    {
        std::cout << c_spPsn->name() << " : " << c_msg << std::endl;
    }
};

class Soldier : public Person, public std::enable_shared_from_this<Soldier>
{
private:
    std::string _name;

public:
    Soldier(const std::string &c_name) : _name(c_name) {}

    virtual ~Soldier() {}

    virtual void say(const std::string &c_msg) { Behavior::say(shared_from_this(), c_msg); }

    virtual std::string name() override { return _name; }
};

int main()
{
    std::shared_ptr<Person> spSoldier{ new Soldier{"Soldier"} };

    /**
     * => Soldier : Defend my country
     */
    spSoldier->say("Defend my country");

    return 0;
}
