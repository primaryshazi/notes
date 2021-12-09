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
             * 阻塞至同时获取两个锁，且当只有成功获取m_mtxOne时才会获取m_mtxTwo
             * 当获取不到m_mtxTwo时，立马释放m_mtxOne，避免产生死锁
             */
            std::lock(_mtxOne, _mtxTwo);
            std::lock_guard<std::mutex> gLockOne(_mtxOne, std::adopt_lock);
            std::lock_guard<std::mutex> gLockTwo(_mtxTwo, std::adopt_lock);

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
        }
    }

    void popFront()
    {
        while (true)
        {
            /**
             * 非阻塞形式尝试加锁，获取不到m_mtxOne时，返回false
             * 当获取m_mtxOne时，未能获取m_mtxTwo，则立马释放m_mtxOne，返回false
             */
            if (std::try_lock(_mtxOne, _mtxTwo))
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

                _mtxOne.unlock();
                _mtxTwo.unlock();
            }
        }
    }

private:
    std::queue<int> _queue;
    std::mutex _mtxOne;
    std::mutex _mtxTwo;
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
