#include "..\tests\tests.hpp"

bool queueTest::nullEnqueue()
{
    QueueNode newNode;
    newNode.getData()->setCNum(1);
    testQueue.enqueue(newNode);
    return true;
}

bool queueTest::oneEnqueue()
{
    QueueNode newNode;
    newNode.getData()->setCNum(2);
    testQueue.enqueue(newNode);
    return true;
}

//call second
bool queueTest::oneDequeue()
{
    testQueue.dequeue();
    assert(testQueue.getpHead()->getData()->getCNum() == 2);
    return true;
}

//call first
bool queueTest::twoDequeue()
{
    testQueue.dequeue();
    assert(testQueue.isEmpty() == 1);
    return true;
}

//i copied main
//if it completes it passed
bool queueTest::run24()
{
    Queue regQueue;
    Queue expressQueue;
    int totalSimTime = 1440;
    int curSimTime = 0;
    int nextExpress = 0;
    int nextReg = 0;
    int totalCustomers = 0;

    while(curSimTime <= totalSimTime)
    {
        //customer creation
        if(nextExpress == 0)
        {
            nextExpress = rand() % 5 + 1;
            QueueNode newNode;
            newNode.getData()->setCNum(1000 + totalCustomers);
            totalCustomers++;
            
            //1-3 mins to service time and total times
            int newServiceTime = rand() % 3 + 1;
            newNode.getData()->setServiceTime(newServiceTime);
            regQueue.updateTotalTime(newServiceTime);
            
            expressQueue.enqueue(newNode);
        }
        if(nextReg == 0)
        {
            nextExpress = rand() % 6 + 3;
            QueueNode newNode;
            newNode.getData()->setCNum(1000 + totalCustomers);
            totalCustomers++;

            //3-5 mins to service time and total times
            int newServiceTime = rand() % 3 + 1;
            newNode.getData()->setServiceTime(newServiceTime);
            regQueue.updateTotalTime(newServiceTime);

            regQueue.enqueue(newNode);
        }

        //time subtraction and dequeue (inside function)
        if(expressQueue.isEmpty() == false)
        {
            expressQueue.passTime();
        }
        if(regQueue.isEmpty() == false)
        {
            regQueue.passTime();
        }

        //print (removed for test)
        /*
        if(curSimTime % 10 && curSimTime != 0)
        {
            std::cout << "Express Queue:" << std::endl;
            expressQueue.printQueue();
            std::cout << "Regular Queue:" << std::endl;
            regQueue.printQueue();
        }
        */

        //reset at 24 hours (i dont feel like making a constant)
        if(curSimTime >= 1440 && totalSimTime > 0)
        {
            curSimTime = 1;
            totalCustomers = 0;
        }

        curSimTime++;
        nextExpress--;
        nextReg--;
    }
    return true;
}