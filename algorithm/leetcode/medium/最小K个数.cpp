#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

std::vector<int> smallestK(std::vector<int> &arr, int k)
{
    if (k <= 0)
    {
        return {};
    }

    std::vector<int> result(k, 0);
    std::priority_queue<int, std::vector<int>, std::greater<int>> minQue;
    for (auto i : arr)
    {
        minQue.emplace(i);
    }

    for (int i = 0; i < k; i++)
    {
        result[i] = minQue.top();
        minQue.pop();
    }

    return result;
}

template <typename T>
void print(const std::vector<T> &v)
{
    for (auto &t : v)
    {
        std::cout << t << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> arr = { 7, 5, 3, 9, 1, 8, 2, 6, 4 };

    /**
     * =>
     * => 1
     * => 1 2
     * => 1 2 3
     * => 1 2 3 4
     * => 1 2 3 4 5
     * => 1 2 3 4 5 6
     * => 1 2 3 4 5 6 7
     * => 1 2 3 4 5 6 7 8
     * => 1 2 3 4 5 6 7 8 9
     */
    for (int i = 0; i < 10; i++)
    {
        print(smallestK(arr, i));
    }

    return 0;
}
