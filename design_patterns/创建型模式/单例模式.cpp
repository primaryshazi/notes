#include <iostream>
#include <string>

class Singleton
{
private:
    Singleton() {}
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;

public:
    ~Singleton() {}

    static Singleton &GetInstance()
    {
        static Singleton single;

        return single;
    }
};

int main()
{
    Singleton &singleOne = Singleton::GetInstance();
    Singleton &singleTwo = Singleton::GetInstance();

    /**
     * => 1
     */
    std::cout << (&singleOne == &singleOne) << std::endl;

    return 0;
}
