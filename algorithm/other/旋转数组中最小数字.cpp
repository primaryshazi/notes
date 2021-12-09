#include <iostream>

int MinOfRotate(int arr[], int length)
{
    if (nullptr == arr || length <= 0)
    {
        return -1;
    }

    int first = 0;
    int last = length - 1;
    int mid = 0;

    while (arr[first] >= arr[last])
    {
        // 当第一个元素与最后一个元素相差1时，last即该值
        if (last - first == 1)
        {
            mid = last;
            break;
        }

        mid = (last - first) / 2 + first;

        // 当出现三者均相等时，用线性扫描，找到最小的值
        if (arr[mid] == arr[first] && arr[mid] == arr[last])
        {
            for (int i = first; i < last + 1; ++i)
            {
                if (mid > arr[i])
                {
                    mid = i;
                }
            }
        }

        /**
         * 中间元素大于首部元素时，目标元素在中间元素左边，将first移动到mid
         * 中间元素大于等于尾部元素时，目标元素在中间元素右边，将last移动到mid
         */
        if (arr[mid] > arr[first])
        {
            first = mid;
        }
        else
        {
            last = mid;
        }
    }

    return arr[mid];
}

int main()
{
    // 旋转数组，将前几个元素移动到尾部即可完成排序
    int arr[] = {5, 6, 7, 8, 9, 1, 2, 3, 4};

    std::cout << MinOfRotate(arr, sizeof(arr) / sizeof(arr[0])) << std::endl;

    return 0;
}
