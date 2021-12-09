#include <iostream>

#define SUM_SOLUTION 5
#define NUMBER_VALUE 10

#if SUM_SOLUTION == 1
class Sum
{
private:
    static int m_num;
    static int m_sum;
public:
    Sum()
    {
        ++m_num;
        m_sum += m_num;
    }

    static int GetSum()
    {
        return Sum::m_sum;
    }
};

int Sum::m_num = 0;
int Sum::m_sum = 0;

int GetSum()
{
    Sum *sum = new Sum[NUMBER_VALUE]();

    delete[] sum;

    return Sum::GetSum();
}
#elif SUM_SOLUTION == 2
class Base
{
public:
    virtual int GetSum(int num)
    {
        return 0;
    }
};

Base *g_arrBase[2] = { nullptr };

class Derived : public Base
{
public:
    virtual int GetSum(int num) override
    {
        return g_arrBase[!!num]->GetSum(num - 1) + num;
    }
};

int GetSum()
{
    Base b;
    Derived d;

    g_arrBase[0] = &b;
    g_arrBase[1] = &d;

    return g_arrBase[1]->GetSum(NUMBER_VALUE);
}
#elif SUM_SOLUTION == 3
template<int n>
class Sum
{
public:
    enum Value
    {
        SUM = Sum<n - 1>::SUM + n
    };
};

template<>
class Sum<1>
{
public:
    enum Value
    {
        SUM = 1
    };
};

int GetSum()
{
    return Sum<NUMBER_VALUE>::SUM;
}
#else
int GetSum()
{
    int sum = 0;

    for (int i = 0; i <= NUMBER_VALUE; i++)
    {
        sum += i;
    }

    return sum;
}
#endif

int main()
{
    /**
     * => 55
     */
    std::cout << GetSum() << std::endl;

    return 0;
}
