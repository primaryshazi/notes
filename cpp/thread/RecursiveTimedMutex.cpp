#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::recursive_timed_mutex rtMtx;
int value = 100;

void foo()
{
    /**
     * rtMtx.try_lock_until() 阻塞到一个时间点，没有拿到锁立即返回false
     * rtMtx.try_lock_for() 阻塞一段时长，没有拿到锁立即返回true
     */
    if (rtMtx.try_lock_for(std::chrono::milliseconds(500)))
    {
        if (value > 0)
        {
            std::cout << value << std::endl;
            value--;
            foo();
        }
    }

    rtMtx.unlock();
}

int main(int argc, char const *argv[])
{
    std::thread t(foo);

    t.join();

    return 0;
}
