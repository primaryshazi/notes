#include <iostream>
#include <memory>
#include <string>

class OS
{
public:
    virtual void insatll() = 0;
};

class Windows : public OS
{
public:
    virtual void insatll() override
    {
        std::cout << "Install Windows" << std::endl;
    }
};

class Linux : public OS
{
public:
    virtual void insatll() override
    {
        std::cout << "Install Linux" << std::endl;
    }
};

class Computer
{
public:
    virtual void insatall(const std::shared_ptr<OS> &c_spOS) = 0;
};

class Apple : public Computer
{
public:
    virtual void insatall(const std::shared_ptr<OS> &c_spOS) override
    {
        c_spOS->insatll();
    }
};

class Huawei : public Computer
{
public:
    virtual void insatall(const std::shared_ptr<OS> &c_spOS) override
    {
        c_spOS->insatll();
    }
};

int main()
{
    std::shared_ptr<Windows> spWindowsOS{ new Windows{} };
    std::shared_ptr<Linux> spLinuxOS{ new Linux{} };

    Apple applePC;
    Huawei huaweiPC;

    /**
     * => Install Windows
     * => Install Linux
     * => Install Windows
     * => Install Linux
     */
    applePC.insatall(spWindowsOS);
    applePC.insatall(spLinuxOS);
    huaweiPC.insatall(spWindowsOS);
    huaweiPC.insatall(spLinuxOS);

    return 0;
}
