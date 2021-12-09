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

    void pushBack()
    {
        while (true)
        {
            _mtx.lock();

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
            // 让出CPU片段时间，避免一直占用CPU
            std::this_thread::yield();
        }
    }

    void popFront()
    {
        while (true)
        {
            _mtx.lock();

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
            std::this_thread::yield();
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

    std::thread pushThread(&Repository::pushBack, &repo);
    std::thread popThread(&Repository::popFront, &repo);

    pushThread.join();
    popThread.join();

    return 0;
}
