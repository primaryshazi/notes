#include <iostream>

// 编译时告警此函数已弃用
[[deprecated]] void deprecatedFunc() {}

// 编译时告警此函数已弃用，并给出原因
[[deprecated("not safe")]] void deprecatedFuncAndResond() {}

int main(int argc, char const* argv[])
{
    deprecatedFunc();
    deprecatedFuncAndResond();

    return 0;
}
