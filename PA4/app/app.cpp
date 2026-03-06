#include "app.hpp"

class app;

void printMenu()
{
    
}

//inclusive
bool validMenuInput(int input, int lowerRange, int higherRange)
{
    if(input >= lowerRange && input <= higherRange)
    {
        return true;
    }
    return false;
}



