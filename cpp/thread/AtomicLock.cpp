#include <iostream>
#include <thread>
#include <atomic>
#include <queue>

class Repository
{
public:
    Repository(const size_t &size = 10)
    {
        _maxSize = size < 10 ? 10 : size;
        _amc.store(false);
    }

    ~Repository() {}

    void pushBack()
    {
        while (true)
        {
            // 获取其值，当其值为false时，进入下一轮循环
            if (!_amc.load())
            {
                continue;
            }

            if (_queue.size() < _maxSize)
            {
                int value = rand();
                std::cout << "push " << value << std::endl;
                _queue.push(value);
            }
            else
            {
                std::cout << "Repository is full" << std::endl;
            }

            // 设置其值
            _amc.store(false);
        }
    }

    void popFront()
    {
        while (true)
        {
            if (_amc.load())
            {
                continue;
            }

            if (!_queue.empty())
            {
                std::cout << "pop " << _queue.front() << std::endl;
                _queue.pop();
            }
            else
            {
                std::cout << "Repository is empty" << std::endl;
            }

            _amc.store(true);
        }
    }

private:
    std::queue<int> _queue;
    std::atomic_bool _amc; // 利用原子操作特性做成类似互斥锁
    size_t _maxSize;
};

int main(int argc, char const *argv[])
{
    Repository repo(1024);

    std::thread pushThread(&Repository::pushBack, &repo);
    std::thread popThread(&Repository::popFront, &repo);

    pushThread.join();
    popThread.join();

    return 0;
}
