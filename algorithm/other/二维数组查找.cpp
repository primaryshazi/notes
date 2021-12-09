#include <iostream>

bool Find(int *matrix, int rows, int columns, int num)
{
    // 从最右上角开始，行左均小于改该，列下均大于该值
    int r = 0;
    int c = columns - 1;

    while (r < rows && c >= 0)
    {
        int value = matrix[r * columns + c];

        /**
         * 当前值比目标值大则减少一列，查找左列
         * 当前值比目标值小则增加一行，查找下行
         */
        if (value > num)
        {
            --c;
        }
        else if (value < num)
        {
            ++r;
        }
        else
        {
            return true;
        }
    }

    return false;
}

int main()
{
    // 行列递增数组
    int arr[] = {
        1, 3, 5,
        4, 6, 8,
        7, 8, 9};

    /**
     * => 0 false
     * => 1 true
     * => 2 false
     * => 3 true
     * => 4 true
     * => 5 true
     * => 6 true
     * => 7 true
     * => 8 true
     * => 9 true
     */
    for (int i = 0; i < 10; ++i)
    {
        std::cout << i << " " << (Find(arr, 3, 3, i) ? "true" : "false") << std::endl;
    }

    return 0;
}
