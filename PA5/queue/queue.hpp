#pragma once

#include <iostream>
#include <string>

#include "..\customer\customer.hpp"

using std::string;

class QueueNode
{
    public: // Member functions
    QueueNode();
    QueueNode(Data* newData);
    ~QueueNode();
    QueueNode* getpNext();
    void setpNext(QueueNode* newData);
    Data* getData();

    private:
    Data* pData; // The memory for Data will need to be allocated on the heap as well!
    QueueNode *pNext;
};

class Queue
{
    public: // Member functions
    Queue();
    ~Queue();
    QueueNode* getpHead();
    void printQueue();
    bool isEmpty();
    bool enqueue(QueueNode* newData);
    Data* dequeue();
    void passTime();
    void updateTotalTime(int newTime);

    private:
    QueueNode* pHead;
    QueueNode* pTail;
    bool empty = 1;
};

