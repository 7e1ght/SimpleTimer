#ifndef SIMPLE_TIMER_CONSUMER
#define SIMPLE_TIMER_CONSUMER

class SimpleTimer;

class SimpleTimerConsumer
{
public:
    virtual void update(SimpleTimer& timer) = 0;
};

#endif // SIMPLER_TIMER_CONSUMER