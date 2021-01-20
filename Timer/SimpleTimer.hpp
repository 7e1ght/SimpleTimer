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

    bool isActive() const;
    int32_t getID() const; 

    ~SimpleTimer();

    SimpleTimer(SimpleTimerConsumer& consumer);
    SimpleTimer(const SimpleTimer& other) = delete;
    SimpleTimer(SimpleTimer&& other) = default;
    const SimpleTimer& operator=(const SimpleTimer& other) = delete;
    SimpleTimer& operator=(SimpleTimer&& other) = default;

private:
    SimpleTimerConsumer& mConsumer;
    bool mActive;
    const int32_t mID;
    static int32_t ID_COUNTER;
    std::thread mThread;
};


#endif // SIMPLE_TIMER