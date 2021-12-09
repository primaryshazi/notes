#include <iostream>

bool IsBSTOfLastPrint(int arr[], int length)
{
    if (nullptr == arr || length <= 0)
    {
        return false;
    }

    int index = 0;  // 左子树最后一个元素的索引
    int root = arr[length - 1];     // 最后一个元素为root

    // 左子树均小于root
    for (; index < length - 1; ++index)
    {
        if (arr[index] > root)
        {
            break;
        }
    }

    // 右子树均大于root
    for (int i = index; i < length - 1; ++i)
    {
        if (arr[i] < root)
        {
            return false;
        }
    }


    bool leftFlag = true;
    bool rightFlag = true;

    // 存在左子树则在左边查找
    if (index > 0)
    {
        leftFlag = IsBSTOfLastPrint(arr, index);
    }

    // 存在右子树则右边查找
    if (index < length - 1)
    {
        rightFlag = IsBSTOfLastPrint(arr + index, length - 1 - index);
    }

    return leftFlag && rightFlag;
}

int main()
{
    /**
     *         5
     *   2            8
     * 1   3        7   9
     *       4   6
     */

    int arr[] = { 1, 4, 3, 2, 6, 7, 9, 8, 5 };

    /**
     * => 1
     */
    std::cout << IsBSTOfLastPrint(arr, sizeof(arr) / sizeof(int)) << std::endl;

    return 0;
}
