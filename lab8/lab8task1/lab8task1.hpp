#include <iostream>
#include <print>

using std::string;

class QueueNode
{
    public:
        QueueNode();
        QueueNode(string str);
        ~QueueNode();
        void setStr(string str);
        string getStr();
        
        
        QueueNode* pNext;
    private:
        
        string data;
};

QueueNode::QueueNode(string newData)
{
    pNext = nullptr;
    data = newData;
}

class Queue
{
    public:
        bool isEmpty();
        bool enqueue(string newData);
        string dequeue();
        void destroyQueue();
        void printQueueRecursive(QueueNode* nextNode);
    private:
    QueueNode* qHead;
    int size = 0;
};

bool Queue::enqueue(string newData)
{
    QueueNode* newNode = new QueueNode(newData);
    QueueNode* cur = qHead;

    while(cur->pNext)
    {
        cur = cur->pNext;
    }
    cur->pNext = newNode;
    return true;
}

string Queue::dequeue()
{
    QueueNode* cur = qHead;
    string out = cur->getStr();
    qHead = qHead->pNext;

    delete cur;
    return out;
}

void Queue::destroyQueue()
{
    QueueNode* cur = qHead;
    QueueNode* pPrev = qHead; 
    while(qHead->pNext != nullptr)
    {
        pPrev = cur;
        cur = cur->pNext;
        delete pPrev;
    }
    delete cur;
}

void Queue::printQueueRecursive(QueueNode* nextNode)
{
    if(nextNode->pNext != nullptr)
    {
        std::cout << nextNode->getStr() << std::endl;
        Queue::printQueueRecursive(nextNode->pNext);
    }
    else
    {
        std::cout << nextNode->getStr() << std::endl;
    }
}