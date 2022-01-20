#include <iostream>
#include <memory>
#include <string>

class Game
{
private:
    virtual void login() = 0;

    virtual void start() = 0;

    virtual void logout() = 0;

public:
    virtual void play() final
    {
        login();
        start();
        logout();
    }
};

class RainbowSix : public Game
{
private:
    virtual void login() override { std::cout << "Log in R6" << std::endl; }

    virtual void start() override { std::cout << "Start R6" << std::endl; }

    virtual void logout() override { std::cout << "Log out R6" << std::endl; }
};

class Battlefield : public Game
{
private:
    virtual void login() override { std::cout << "Log in BF" << std::endl; }

    virtual void start() override { std::cout << "Start BF" << std::endl; }

    virtual void logout() override { std::cout << "Log out BF" << std::endl; }
};

int main()
{
    std::shared_ptr<Game> spR6 = std::make_shared<RainbowSix>();
    std::shared_ptr<Game> spBF = std::make_shared<Battlefield>();

    /**
     * => Log in R6
     * => Start R6
     * => Log out R6
     * => Log in BF
     * => Start BF
     * => Log out BF
     */
    spR6->play();
    spBF->play();

    return 0;
}
