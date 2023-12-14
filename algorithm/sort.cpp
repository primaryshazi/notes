#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <limits>
#include <numeric>
#include <functional>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <cmath>

#define VARIABLE_TO_STRING(x) (#x)

typedef int64_t index_type;

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v)
{
    os << "{ ";
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        if (it != v.begin())
        {
            os << ", ";
        }
        os << *it;
    }
    os << " }";

    return os;
}

std::vector<int> generate(size_t num)
{
    if (num == 0)
    {
        return {};
    }

    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<int> uniform(0, std::numeric_limits<int16_t>::max());
    std::vector<int> array(num, 0);

    for (size_t i = 0; i < num; ++i)
    {
        array[i] = uniform(engine);
    }

    return array;
}

void bubble_sort(std::vector<int> &array)
{
    index_type length = static_cast<index_type>(array.size());
    if (length < 2)
    {
        return;
    }

    for (index_type i = 0; i < length - 1; ++i)
    {
        for (index_type j = 0; j < length - 1 - i; ++j)
        {
            if (array[j] > array[j + 1])
            {
                std::swap(array[j], array[j + 1]);
            }
        }
    }
}

void select_sort(std::vector<int> &array)
{
    index_type length = static_cast<index_type>(array.size());
    if (length < 2)
    {
        return;
    }

    for (index_type i = 0; i < length; i++)
    {
        index_type index = i;

        for (index_type j = i + 1; j < length; ++j)
        {
            if (array[j] < array[index])
            {
                index = j;
            }
        }

        if (index != i)
        {
            std::swap(array[index], array[i]);
        }
    }
}

void insert_sort(std::vector<int> &array)
{
    index_type length = static_cast<index_type>(array.size());
    if (length < 2)
    {
        return;
    }

    for (index_type i = 0; i < length; ++i)
    {
        index_type index = i;
        auto tmp = array[i];

        while (index > 0 && array[index - 1] > tmp)
        {
            array[index] = array[index - 1];
            --index;
        }

        array[index] = tmp;
    }
}

void shell_sort(std::vector<int> &array)
{
    index_type length = static_cast<index_type>(array.size());
    if (length < 2)
    {
        return;
    }

    for (index_type span = length / 2; span > 0; span /= 2)
    {
        for (index_type i = span; i < length; ++i)
        {
            index_type index = i;
            auto tmp = array[i];

            while (index >= span && array[index - span] > tmp)
            {
                array[index] = array[index - span];
                index -= span;
            }

            array[index] = tmp;
        }
    }
}

void heap_sort(std::vector<int> &array)
{
    index_type length = static_cast<index_type>(array.size());
    if (length < 2)
    {
        return;
    }

    std::function<void(std::vector<int> &, index_type, index_type)> build_heap =
        [&build_heap](std::vector<int> &array, index_type length, index_type index)
    {
        index_type father = index;
        index_type lchild = 2 * index + 1;
        index_type rchild = 2 * index + 2;

        // 找到比子节点中比父节点大的值，并与之交换，然后向下递推
        if (lchild < length && array[father] < array[lchild])
        {
            father = lchild;
        }
        if (rchild < length && array[father] < array[rchild])
        {
            father = rchild;
        }

        if (father != index)
        {
            std::swap(array[father], array[index]);
            build_heap(array, length, father);
        }
    };

    for (int i = length - 1; i >= 0; --i)
    {
        build_heap(array, length, i);
    }

    for (int i = length - 1; i >= 0; --i)
    {
        std::swap(array[i], array[0]);
        build_heap(array, i, 0);
    }
}

void merge_sort(std::vector<int> &array)
{
    index_type length = static_cast<index_type>(array.size());
    if (length < 2)
    {
        return;
    }

    std::vector<int> tmp(length);

    std::function<void(std::vector<int> &, index_type, index_type, index_type)> merge =
        [&tmp](std::vector<int> &array, index_type left, index_type mid, index_type right)
    {
        index_type lIdx = left;
        index_type rIdx = mid + 1;
        index_type index = 0;

        // 将数组分为两组，按大小归并入原数组
        while (lIdx <= mid && rIdx <= right)
        {
            if (array[lIdx] <= array[rIdx])
            {
                tmp[index++] = array[lIdx++];
            }
            else
            {
                tmp[index++] = array[rIdx++];
            }
        }

        while (lIdx <= mid)
        {
            tmp[index++] = array[lIdx++];
        }

        while (rIdx <= right)
        {
            tmp[index++] = array[rIdx++];
        }

        index = 0;
        while (left <= right)
        {
            array[left++] = tmp[index++];
        }
    };
    std::function<void(std::vector<int> &, index_type, index_type)> mg_sort =
        [&merge, &mg_sort](std::vector<int> &array, index_type left, index_type right)
    {
        if (left < right)
        {
            index_type mid = left + ((right - left) >> 1);
            mg_sort(array, left, mid);
            mg_sort(array, mid + 1, right);
            merge(array, left, mid, right);
        }
    };

    mg_sort(array, 0, length - 1);
}

void quick_sort(std::vector<int> &array)
{
    index_type length = static_cast<index_type>(array.size());
    if (length < 2)
    {
        return;
    }

    std::default_random_engine engine(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<index_type> uniform;
    std::function<index_type(std::vector<int> &, index_type, index_type)> partition =
        [&engine, &uniform](std::vector<int> &array, index_type left, index_type right) -> index_type
    {
        index_type stdIdx = uniform(engine, decltype(uniform)::param_type{left, right});
        std::swap(array[right], array[stdIdx]);

        int standard = array[right];
        index_type index = left;

        for (index_type i = left; i < right; ++i)
        {
            if (array[i] < standard)
            {
                std::swap(array[i], array[index++]);
            }
        }
        std::swap(array[index], array[right]);

        return index;
    };
    std::function<void(std::vector<int> &, index_type, index_type)> qc_sort =
        [&partition, &qc_sort](std::vector<int> &array, index_type left, index_type right)
    {
        if (left < right)
        {
            index_type index = partition(array, left, right);
            qc_sort(array, left, index - 1);
            qc_sort(array, index + 1, right);
        }
    };

    qc_sort(array, 0, length - 1);
}

void count_sort(std::vector<int> &array)
{
    index_type length = static_cast<index_type>(array.size());
    if (length < 2)
    {
        return;
    }

    int maxValue = *std::max_element(array.begin(), array.end());
    std::vector<int> count(maxValue + 1, 0);

    // 记录每一个数字出现的次数
    for (auto i : array)
    {
        ++count[i];
    }

    index_type countSize = static_cast<index_type>(count.size());

    // 写入到原始的数组
    for (index_type i = 0, index = 0; i < countSize; ++i)
    {
        for (index_type j = 0; j < count[i]; ++j)
        {
            array[index++] = i;
        }
    }
}

void radix_sort(std::vector<int> &array)
{
    index_type length = static_cast<index_type>(array.size());
    if (length < 2)
    {
        return;
    }

    int maxValue = *std::max_element(array.begin(), array.end());
    index_type digit = std::floor(log10(maxValue)) + 1;
    std::vector<std::vector<int>> radix(10);

    // 从个位数开始，将每个数放置于不同的基数上
    for (index_type d = 0; d < digit; ++d)
    {
        for (auto i : array)
        {
            double ratio = std::pow(10, d);
            index_type index = i % static_cast<index_type>(ratio * 10) / ratio;
            radix[index].emplace_back(i);
        }

        index_type index = 0;
        for (auto &rad : radix)
        {
            for (auto i : rad)
            {
                array[index++] = i;
            }
            rad.clear();
        }
    }
}

void bucket_sort(std::vector<int> &array)
{
    index_type length = static_cast<index_type>(array.size());
    if (length < 2)
    {
        return;
    }

    auto minmax = std::minmax_element(array.begin(), array.end());
    int minValue = *minmax.first;
    int maxValue = *minmax.second;
    index_type bkSize = (maxValue - minValue) / length + 1;
    std::vector<std::vector<int>> bucket(bkSize);

    // 将每个元素放置到指定的桶中
    for (auto i : array)
    {
        index_type index = (i - minValue) / length;
        bucket[index].emplace_back(i);
    }

    // 对每个桶分别进行排序
    for (auto &bk : bucket)
    {
        std::sort(bk.begin(), bk.end());
    }

    index_type index = 0;

    // 写入到原始的数组
    for (auto &bk : bucket)
    {
        for (auto i : bk)
        {
            array[index++] = i;
        }
    }
}

void std_sort(std::vector<int> &array)
{
    std::sort(array.begin(), array.end());
}

int main()
{
    try
    {
        std::vector<std::pair<std::string, std::function<void(std::vector<int> &)>>> vFunc = {
            {VARIABLE_TO_STRING(bubble_sort), bubble_sort},
            {VARIABLE_TO_STRING(select_sort), select_sort},
            {VARIABLE_TO_STRING(insert_sort), insert_sort},
            {VARIABLE_TO_STRING(shell_sort), shell_sort},
            {VARIABLE_TO_STRING(heap_sort), heap_sort},
            {VARIABLE_TO_STRING(merge_sort), merge_sort},
            {VARIABLE_TO_STRING(quick_sort), quick_sort},
            {VARIABLE_TO_STRING(count_sort), count_sort},
            {VARIABLE_TO_STRING(radix_sort), radix_sort},
            {VARIABLE_TO_STRING(bucket_sort), bucket_sort},
            {VARIABLE_TO_STRING(std_sort), std_sort},
        };

        const auto original_array = generate(10000);
        for (auto &func : vFunc)
        {
            auto array = original_array;
            int64_t start = std::chrono::high_resolution_clock::now().time_since_epoch().count();
            func.second(array);
            int64_t end = std::chrono::high_resolution_clock::now().time_since_epoch().count();

            std::cout << std::setw(12) << std::right << func.first << std::setw(15) << std::right << std::fixed << std::setprecision(3)
                      << static_cast<double>(end - start) / 1000000 << std::setw(8) << std::right
                      << (std::is_sorted(array.begin(), array.end()) ? "true" : "false") << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
