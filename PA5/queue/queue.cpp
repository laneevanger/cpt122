#include "..\queue\queue.hpp"

//QueueNode

QueueNode::QueueNode()
{
    pData = new Data();
    pNext = nullptr;
}

QueueNode::QueueNode(Data* newData)
{
    pData = newData;
}

QueueNode::~QueueNode()
{
    delete pData; // QueueNode owns pData, so it cleans it up
    pData = nullptr;
}

QueueNode* Queue::getpHead()
{
    return pHead;
}

QueueNode* QueueNode::getpNext()
{
    return pNext;
}

void QueueNode::setpNext(QueueNode* newData)
{
    pNext = newData;
}

Data* QueueNode::getData()
{
    return pData;
}

//queue

Queue::Queue()
{
    pHead = nullptr;
    pTail = nullptr;
}

Queue::~Queue()
{
    while (pHead != nullptr)
    {
        dequeue(); // dequeue already deletes nodes
    }
}

void Queue::printQueue()
{
    QueueNode* cur = pHead;

    while(cur != nullptr)
    {
        std::cout << (*(cur)->getpNext()).getData()->getCNum() << std::endl; 
        cur = cur->getpNext();
    }
    
}

bool Queue::isEmpty()
{
    if(pHead == nullptr)
    {
        empty = true;
        return true;
    }
    return false;
}

bool Queue::enqueue(QueueNode newData)
{
    QueueNode* newNode = new QueueNode(newData);
    QueueNode* cur = pHead;

    if (pHead == nullptr) 
    {
        pHead = newNode;
        pTail = newNode;
        return true;
    }
    while(cur->getpNext() != nullptr)
    {
        cur = cur->getpNext();
    }
    cur->setpNext(newNode);
    pTail = newNode;
    empty = false;

    return true;
}

Data* Queue::dequeue()
{
    if(pHead != nullptr)
    {
        QueueNode* cur = pHead;
        Data* out = cur->getData();
        pHead = cur->getpNext();
        if(pHead == nullptr)
        {
            empty = true;
        }
        delete cur;
        return out;
    }

    empty = true;
    return nullptr;
}

void Queue::passTime()
{
    pHead->getData()->setServiceTime(pHead->getData()->getServiceTime() - 1);
    pHead->getData()->setTotalTime(pHead->getData()->getTotalTime() - 1);
    QueueNode* cur = pHead;
    while(cur->getpNext() != nullptr)
    {
        cur = cur->getpNext();
        cur->getData()->setTotalTime(cur->getData()->getTotalTime() - 1);
    }

    if(pHead->getData()->getServiceTime() < 1)
    {
        dequeue();
    }
}

void Queue::updateTotalTime(int newTime)
{
    QueueNode* cur = pHead;
    while (cur != nullptr)
    {
        cur->getData()->setTotalTime(cur->getData()->getTotalTime() + newTime);
        cur = cur->getpNext();
    }
    
}