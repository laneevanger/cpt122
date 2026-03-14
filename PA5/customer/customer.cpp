#include "..\customer\customer.hpp"

Data::Data() 
{ 
    serviceTime = 0; 
    totalTime = 0; 
}

//default
Data::~Data()
{

}

int Data::getCNum()
{
    return customerNumber;
}

void Data::setCNum(int num)
{
    customerNumber = num;
}

int Data::getTotalTime()
{
    return totalTime;
}

void Data::setTotalTime(int newTime)
{
    totalTime = newTime;
}

int Data::getServiceTime()
{
    return serviceTime;
}

void Data::setServiceTime(int newTime)
{
    serviceTime = newTime;
}