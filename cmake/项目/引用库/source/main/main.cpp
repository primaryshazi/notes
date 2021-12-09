#include "HelloWorld.h"
#include "AreYouOK.h"

#include <iostream>

int main(int argc, char const *argv[])
{
    std::cout << HelloWorld::Say() << std::endl;
    std::cout << AreYouOK::Say() << std::endl;

    return 0;
}
