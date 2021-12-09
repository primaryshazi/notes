#include <iostream>

class A
{
public:
    A(int value) : _value(value) {}
    virtual ~A() {}

    void print()
    {
        // 以拷贝形式捕获*this
        [*this] { std::cout << this->_value << " " << &(this->_value) << std::endl; }();
        [=, *this] { std::cout << this->_value << " " << &(this->_value) << std::endl; }();

        std::cout << this->_value << " " << &(this->_value) << std::endl;
    }

private:
    int _value;
};

int main()
{
    A a(1024);

    /**
     * => 1024 0xb8ca5ffb78
     * => 1024 0xb8ca5ffb88
     * => 1024 0xb8ca5ffbd8
     */
    a.print();

    return 0;
}
