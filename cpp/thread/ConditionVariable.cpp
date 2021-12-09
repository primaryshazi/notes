#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>

class Repository
{
public:
    Repository(const size_t &size = 10)
    {
        _maxSize = size < 10 ? 10 : size;
        _isFull = false;
    }

    ~Repository() {}

    void pushBack()
    {
        while (true)
        {
            std::unique_lock<std::mutex> uLock(_mtx);

            /**
             * m_cv.wait()          阻塞等待通知和谓词为真
             * m_cv.wait_for()      在指定的时段内未等到通知和谓词为真，返回false
             * m_cv.wait_until()    在指定时间点之气那未未等到通知和谓词为真，返回false
             */
            m_cv.wait(uLock, [&]
                      { return _queue.empty(); });

            while (_queue.size() <= _maxSize)
            {
                int value = rand();
                std::cout << "push " << value << std::endl;
                _queue.push(value);
            }
            std::cout << "Repository is full" << std::endl;
            uLock.unlock();

            /**
             * m_cv.notify_one()    随机通知任意一个处于等待阶段的线程
             * m_cv.notify_all()    通知所有处于等待阶段的线程
             */
            m_cv.notify_all();
        }
    }

    void popFront()
    {
        while (true)
        {
            std::unique_lock<std::mutex> uLock(_mtx);

            m_cv.wait(uLock, [&]
                      { return _queue.size() >= _maxSize; });

            while (!_queue.empty())
            {
                std::cout << "pop " << _queue.front() << std::endl;
                _queue.pop();
            }
            std::cout << "Repository is empty" << std::endl;
            uLock.unlock();
            m_cv.notify_all();
        }
    }

private:
    std::queue<int> _queue;
    std::mutex _mtx;
    size_t _maxSize;
    std::condition_variable m_cv; // 只能与std::unique_lock进行绑定
    bool _isFull;
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
