#include <iostream>
#include <tuple>

// 数组拷贝绑定
void structArrBind()
{
    int arr[] = { 1, 2, 3 };
    auto [x, y, z] = arr;

    x++;
    y++;
    z++;

    /**
     * => 1 2 3
     * => 2 3 4
     */
    std::cout << arr[0] << " " << arr[1] << " " << arr[2] << std::endl;
    std::cout << x << " " << y << " " << z << std::endl;
}

// 数组引用绑定
void structArrReferenceBind()
{
    int arr[] = { 1, 2, 3 };
    auto& [x, y, z] = arr;

    x++;
    y++;
    z++;

    /**
     * => 2 3 4
     * => 2 3 4
     */
    std::cout << arr[0] << " " << arr[1] << " " << arr[2] << std::endl;
    std::cout << x << " " << y << " " << z << std::endl;
}

// 元组绑定
void structTupleBind()
{
    int arr[] = { 1, 2, 3 };
    std::tuple<int, int&, int&&> tpl(arr[0], arr[1], std::move(arr[2]));
    auto& [x, y, z] = tpl;

    x++;
    y++;
    z++;

    /**
     * => 2 3 4
     * => 2 3 4
     */
    std::cout << std::get<0>(tpl) << " " << std::get<1>(tpl) << " " << std::get<2>(tpl) << std::endl;
    std::cout << x << " " << y << " " << z << std::endl;
}

int main()
{
    structArrBind();
    structArrReferenceBind();
    structTupleBind();

    return 0;
}
