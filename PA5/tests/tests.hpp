#pragma once

#include <cassert>

#include "..\queue\queue.hpp"

class queueTest
{
    public:
    bool nullEnqueue();
    bool oneEnqueue();
    bool oneDequeue();
    bool twoDequeue();
    bool run24();
    private:
    Queue testQueue;
};