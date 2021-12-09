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
            /**
             * _tMtx.try_lock_until() 阻塞到一个时间点，没有拿到锁立即返回false
             * _tMtx.try_lock_for() 阻塞一段时长，没有拿到锁立即返回false
             */
            if (_tMtx.try_lock_for(std::chrono::milliseconds(500)))
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

                _tMtx.unlock();
            }
        }
    }

    void popFront()
    {
        while (true)
        {
            // 不阻塞，拿不到锁立即返回false
            if (_tMtx.try_lock())
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

                _tMtx.unlock();
            }
        }
    }

private:
    std::queue<int> _queue;
    std::timed_mutex _tMtx;
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
