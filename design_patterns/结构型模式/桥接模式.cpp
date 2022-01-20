#include <iostream>
#include <memory>
#include <string>

class OS
{
public:
    virtual void install() = 0;
};

class Windows : public OS
{
public:
    virtual void install() override
    {
        std::cout << "Install Windows" << std::endl;
    }
};

class Linux : public OS
{
public:
    virtual void install() override
    {
        std::cout << "Install Linux" << std::endl;
    }
};

class Computer
{
public:
    virtual void install(const std::shared_ptr<OS> &spOS) = 0;
};

class Apple : public Computer
{
public:
    virtual void install(const std::shared_ptr<OS> &spOS) override
    {
        spOS->install();
    }
};

class Huawei : public Computer
{
public:
    virtual void install(const std::shared_ptr<OS> &spOS) override
    {
        spOS->install();
    }
};

int main()
{
    std::shared_ptr<Windows> spWindowsOS = std::make_shared<Windows>();
    std::shared_ptr<Linux> spLinuxOS = std::make_shared<Linux>();

    Apple applePC;
    Huawei huaweiPC;

    /**
     * => Install Windows
     * => Install Linux
     * => Install Windows
     * => Install Linux
     */
    applePC.install(spWindowsOS);
    applePC.install(spLinuxOS);
    huaweiPC.install(spWindowsOS);
    huaweiPC.install(spLinuxOS);

    return 0;
}
