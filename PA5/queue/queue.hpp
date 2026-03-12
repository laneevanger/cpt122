#include "..\customer\customer.hpp"

class QueueNode
{
    public: // Member functions

    private:
    Data *pData; // The memory for Data will need to be allocated on the heap as well!
    QueueNode *pNext;
};

class Queue
{
    public: // Member functions
    void printQueue();
    bool isEmpty();
    private:
    QueueNode* pHead;
    QueueNode* pTail;
    bool isEmpty = 1;
};

void Queue::printQueue()
{
    
}

