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
            // 构造时加锁，析构时解锁，可以转移所有权
            std::unique_lock<std::mutex> uLock(_mtx);

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

            // 提前解锁
            uLock.unlock();
        }
    }

    void popFront()
    {
        while (true)
        {
            /**
             * std::defer_lock      不获得互斥的所有权
             * try_to_lock          尝试获得互斥的所有权而不阻塞
             * adopt_lock           假设调用方线程已拥有互斥的所有权
             */
            std::unique_lock<std::mutex> uLock(_mtx, std::defer_lock);

            // 此时加锁
            uLock.lock();

            if (!_queue.empty())
            {
                std::cout << "pop " << _queue.front() << std::endl;
                _queue.pop();
            }
            else
            {
                std::cout << "Repository is empty" << std::endl;
            }

            // 此时解锁
            uLock.unlock();
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
