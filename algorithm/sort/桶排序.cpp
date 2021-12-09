#include <algorithm>
#include <vector>

void bucketSort(int arr[], int N)
{
    std::vector<std::vector<int>> bucket;

    // bucket.size() / N越大则时间复杂度越低，空间复杂度越高
    bucket.resize(N);

    // 将每个元素放入指定的桶中
    for (int i = 0; i < N; ++i)
    {
        bucket[arr[i]].emplace_back(arr[i]);
    }

    // 对每个桶进行排序
    for (int i = 0; i < N; ++i)
    {
        std::sort(bucket[i].begin(), bucket[i].end());
    }

    // 将桶中的元素取出放回数组
    for (size_t i = 0, index = 0; i < bucket.size(); ++i)
    {
        for (size_t j = 0; j < bucket[i].size(); ++j)
        {
            arr[index++] = bucket[i][j];
        }
    }
}
