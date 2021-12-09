#include <iostream>

// 指示从前一 case 标号直落是有意的，编译器不警告
void fallthroughCase(int value)
{
    switch (value)
    {
    case 0:
        [[fallthrough]];
    case 1:
        [[fallthrough]];
    case 2:
        [[fallthrough]];
    default:
        break;
    }
}

// 若返回值被舍弃，则鼓励编译器发布警告
[[nodiscard]] int nodiscardFunc(int value)
{
    return value;
}

// 压制编译器在未使用实体上的警告
void maybeUnused([[maybe_unused]] int vlaue)
{
}

int main(int argc, char const* argv[])
{
    fallthroughCase(1);
    nodiscardFunc(1);
    maybeUnused(1);

    return 0;
}
