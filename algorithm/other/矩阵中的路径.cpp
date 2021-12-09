#include <iostream>
#include <cstring>

bool HasPathCore(const char *matrix, int row, int column, int r, int c, const char *str, bool *visit, int *pathLength)
{
    // 当字符路径已走完则返回成功
    if ('\0' == str[*pathLength])
    {
        return true;
    }

    bool hasPath = false;

    // 当前矩阵中的的字符与字符路径字符相同且该字符未标记已占用
    if (r >= 0 && c >= 0 &&
        r < row && c < column &&
        matrix[r * column + c] == str[*pathLength] &&
        !visit[r * column + c])
    {
        // 标记该字符路径正确
        ++(*pathLength);
        visit[r * column + c] = true;

        // 判断其周围路径是否正确
        hasPath = HasPathCore(matrix, row, column, r, c - 1, str, visit, pathLength) ||
            HasPathCore(matrix, row, column, r, c + 1, str, visit, pathLength) ||
            HasPathCore(matrix, row, column, r - 1, c, str, visit, pathLength) ||
            HasPathCore(matrix, row, column, r + 1, c, str, visit, pathLength);

        // 若其周围路径不正确则退回标记
        if (!hasPath)
        {
            --(*pathLength);
            visit[r * column + c] = false;
        }
    }

    return hasPath;
}

bool HasPath(char *matrix, int row, int column, const char *str)
{
    if (nullptr == matrix || row <= 0 || column <= 0 || nullptr == str)
    {
        return false;
    }

    int pathLength = 0; // 记录当前路径长度
    bool *visit = new bool[row * column](); // 记录成功访问的路径
    memset(visit, 0, row * column);

    // 遍历该矩阵中所有的字符
    for (int r = 0; r < row; ++r)
    {
        for (int c = 0; c < column; ++c)
        {
            if (HasPathCore(matrix, row, column, r, c, str, visit, &pathLength))
            {
                return true;
            }
        }
    }

    delete[] visit;

    return false;
}

int main()
{
    char matrix[] = {
        'a', 'b', 'c', 'd',
        'e', 'f', 'g', 'h',
        'i', 'j', 'k', 'l',
        'm', 'n', 'o', 'p'
    };
    const char *str = "fgklp";

    std::cout << HasPath(matrix, 4, 4, str) << std::endl;

    return 0;
}
