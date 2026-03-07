#include "app.hpp"

void FitnessAppWrapper::printMenu()
{
    std::cout << "1. Load weekly diet plan from file" << std::endl;
    std::cout << "2. Load weekly exercise plan from file" << std::endl;
    std::cout << "3. Store weekly diet plan to file" << std::endl;
    std::cout << "4. Store weekly exercise plan to file" << std::endl;
    std::cout << "5. Display weekly diet plan to screen" << std::endl;
    std::cout << "6. Display weekly exercise plan to screen" << std::endl;
    std::cout << "7. Edit daily diet plan" << std::endl;
    std::cout << "8. Edit daily exercise plan" << std::endl;
    std::cout << "9. Exit" << std::endl;
}

//inclusive
bool FitnessAppWrapper::validMenuInput(int input, int lowerRange, int higherRange)
{
    if(input >= lowerRange && input <= higherRange)
    {
        return true;
    }
    return false;
}

void FitnessAppWrapper::runApp()
{
    int quit = 0;
    do
    {
        
    }while (quit == 0);
    
    int selection;
    do
    {
        printMenu();
        std::cout << "Choice:" << std::endl;
        std::cin >> selection;
    }while(validMenuInput(selection, 1, 9) != 1);

    std::ifstream inputStream;
    std::ofstream outputStream;
    
    switch (selection)
    {
    case LOADWDP:
        inputStream.open("dietPlans.txt");

        inputStream.close();
        break; 
    case LOADWEP:
        inputStream.open("excercisePlans.txt");

        inputStream.close();
        break;
    case STOREWDP:
        outputStream.open("dietPlans.txt");

        outputStream.close();
        break;
    case STOREWEP:
        outputStream.open("excercisePlans.txt");

        outputStream.close();
        break;
    case DISPLAYWDP:
        /* code */
        break;
    case DISPLAYWEP:
        /* code */
        break;
    case EDITDDP:
        /* code */
        break;
    case EDITDEP:
        /* code */
        break;
    case EXIT:
        //store both weekly plans
        quit = 1;
        break;
    }
}

//repeat for exercise

//std::ifstream inputFile;
//inputFile.open("input.txt");

//std::ofstream outputFile;
//outputFile.open("output.txt");

//inputFile.close();
//outputFile.close();

//getln
void loadDailyPlan (ifstream &fileStream, DietPlan &plan)
{

}

void loadWeeklyPlan (ifstream &fileStream, DietPlan weeklyPlan[])
{
    
}

void displayWeeklyPlan ()
{

}

void storeDailyPlan (ofstream &fileStream, DietPlan &plan)
{

}

void storeWeeklyPlan (ofstream &fileStream, DietPlan weeklyPlan[])
{

}




