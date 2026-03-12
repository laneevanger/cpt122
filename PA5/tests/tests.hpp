#include "..\queue\queue.hpp"

class queueTest
{
    public:
    bool nullEnqueue();
    bool oneEnqueue();
    bool oneDequeue();
    bool twoDequeue();
    private:
    Queue testQueue;
};