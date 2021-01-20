#ifndef SIMPLE_TIMER
#define SIMPLE_TIMER

#include <cstdint>
#include <limits>
#include <thread>


#include "SimpleTimerConsumer.hpp"

class SimpleTimer
{
public:
    enum Type
    {
        CONTINUES = std::numeric_limits<int64_t>::max()
    };

    void start(const int32_t interval, const int64_t times);    
    void stop();
    SimpleTimer(SimpleTimerConsumer& consumer);

    bool isActive() const;
    int32_t getID() const; 

    ~SimpleTimer();

private:
    SimpleTimerConsumer& mConsumer;
    bool mActive;
    const int32_t mID;
    static int32_t ID_COUNTER;
    std::thread mThread;
};


#endif // SIMPLE_TIMER