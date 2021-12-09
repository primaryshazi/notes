#include <iostream>
#include <thread>
#include <atomic>
#include <queue>

class Repository
{
public:
    Repository(const size_t &size = 10) : _flag(ATOMIC_FLAG_INIT)
    {
        _maxSize = size < 10 ? 10 : size;
    }

    ~Repository() {}

    void pushBack()
    {
        while (true)
        {
            // 返回m_flag当前的值后将其置为true
            while (_flag.test_and_set())
                ;

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

            // 将其置为false
            _flag.clear();
        }
    }

    void popFront()
    {
        while (true)
        {
            while (_flag.test_and_set())
                ;

            if (!_queue.empty())
            {
                std::cout << "pop " << _queue.front() << std::endl;
                _queue.pop();
            }
            else
            {
                std::cout << "Repository is empty" << std::endl;
            }

            _flag.clear();
        }
    }

private:
    std::queue<int> _queue;
    std::atomic_flag _flag; // 利用std::atomic_flag完成自旋锁
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
