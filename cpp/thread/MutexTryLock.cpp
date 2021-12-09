#include <iostream>
#include <thread>
#include <mutex>
#include <queue>

class Repository
{
public:
    Repository(const size_t &size = 10)
    {
        _maxSize = size < 10 ? 10 : size;
    }

    ~Repository() {}

    void pushBackTry()
    {
        while (true)
        {
            // 尝试获取锁，当获取到则返回真，未获取到则返回假
            if (_mtx.try_lock())
            {
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

                _mtx.unlock();
            }
        }
    }

    void popFrontTry()
    {
        while (true)
        {
            if (_mtx.try_lock())
            {
                if (!_queue.empty())
                {
                    std::cout << "pop " << _queue.front() << std::endl;
                    _queue.pop();
                }
                else
                {
                    std::cout << "Repository is empty" << std::endl;
                }

                _mtx.unlock();
            }
        }
    }

private:
    std::queue<int> _queue;
    std::mutex _mtx;
    size_t _maxSize;
};

int main(int argc, char const *argv[])
{
    Repository repo(1024);

    std::thread pushThread(&Repository::pushBackTry, &repo);
    std::thread popThread(&Repository::popFrontTry, &repo);

    pushThread.join();
    popThread.join();

    return 0;
}
