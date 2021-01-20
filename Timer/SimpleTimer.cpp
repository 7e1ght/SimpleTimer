#include <chrono>
#include <iostream>

#include "SimpleTimer.hpp"

int32_t SimpleTimer::ID_COUNTER = 0;

SimpleTimer::SimpleTimer(SimpleTimerConsumer& consumer) 
: mConsumer(consumer)
, mActive(false)
, mID(++ID_COUNTER)
, mThread{}
{}

bool SimpleTimer::isActive() const
{
   return mActive;
}

void SimpleTimer::start(const int32_t interval, const int64_t times)
{
   if(false == mActive)
   {
      mActive = true;
      mThread = std::thread(
      [&, times, interval]()
      {
         auto time = std::chrono::steady_clock::now();
         int64_t n = 0;
         while (true == mActive && n < times)
         {
            auto diff = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - time).count(); 

            if(diff >= interval)
            {
               mConsumer.update(*this);
               time = std::chrono::steady_clock::now();
               n++;
            }
         }
         mActive = false;
      });
   }
}

void SimpleTimer::stop()
{
   mActive = false;
}

int32_t SimpleTimer::getID() const
{
   return mID;
}

SimpleTimer::~SimpleTimer()
{
   stop();
   mThread.join();
}