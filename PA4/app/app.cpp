#include "app.hpp"

//actual app stuff

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
    if (input >= lowerRange && input <= higherRange)
    {
        return true;
    }
    return false;
}

//main in app (i dont get the point of this i dont know if i did it right)
void FitnessAppWrapper::runApp()
{
    int selection;
    int day;
    //im getting lazy
    std::string tempStr;
    int tempInt;

    int quit = 0;
    do
    {
        selection = 0;
        do
        {
            clearScreen();
            printMenu();
            std::cout << "Choice:" << std::endl;
            std::cin >> selection;
            //these fix pause not working properly (doesnt actually work)
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } while (validMenuInput(selection, 1, 9) != 1);

        std::ifstream inputStream;
        std::ofstream outputStream;
        //the voices told me i had to do this, only half get why its different from the other 2, worst way to do this tho 100%
        std::ostream& consoleOutputStream = std::cout;

        clearScreen();
        switch (selection)
        {
        case LOADWDP:
            inputStream.open("dietPlans.txt");
            loadWeeklyPlan(inputStream, dPlan);
            inputStream.close();
            break;

        case LOADWEP:
            inputStream.open("excercisePlans.txt");
            loadWeeklyPlan(inputStream, ePlan);
            inputStream.close();
            break;

        case STOREWDP:
            outputStream.open("dietPlans.txt");
            storeWeeklyPlan(outputStream, dPlan);
            outputStream.close();
            break;

        case STOREWEP:
            outputStream.open("excercisePlans.txt");
            storeWeeklyPlan(outputStream, ePlan);
            outputStream.close();
            break;

        case DISPLAYWDP:
            displayWeeklyPlan(consoleOutputStream, dPlan);
            pauseScreen();
            break;

        case DISPLAYWEP:
            displayWeeklyPlan(consoleOutputStream, ePlan);
            pauseScreen();
            break;

        case EDITDDP:
            selection = 0;
            do
            {
                clearScreen();
                std::cout << "1. Name" << std::endl;
                std::cout << "2. Goal" << std::endl;
                std::cout << "3. Day" << std::endl;
                std::cout << "4. Month" << std::endl;
                std::cout << "5. Year" << std::endl;
                std::cout << "6. Cancel" << std::endl;
                std::cout << "Choice:" << std::endl;

                std::cin >> selection;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } while (validMenuInput(selection, 1, 6) != 1);

            do
            {
                clearScreen();
                std::cout << "Which day(1-7)" << std::endl;
                std::cout << "Choice:" << std::endl;

                std::cin >> day;
            } while (validMenuInput(day, 1, 7) != 1);
            
            clearScreen();
            if (selection == 1)
            {
                std::cout << "Enter new name" << std::endl;
                std::cin >> tempStr;
                dPlan[day].setName(tempStr);
            }
            else if (selection == 2)
            {
                std::cout << "Enter new goal" << std::endl;
                std::cin >> tempInt;
                dPlan[day].setGoal(tempInt);
            }
            else if (selection == 3)
            {
                std::cout << "Enter new day" << std::endl;
                std::cin >> tempInt;
                dPlan[day].setDay(tempInt);
            }
            else if (selection == 4)
            {
                std::cout << "Enter new month" << std::endl;
                std::cin >> tempInt;
                dPlan[day].setMonth(tempInt);
            }
            else if (selection == 5)
            {
                std::cout << "Enter new year" << std::endl;
                std::cin >> tempInt;
                dPlan[day].setYear(tempInt);
            }
            break;

        case EDITDEP:
            selection = 0;
            do
            {
                clearScreen();
                std::cout << "1. Name" << std::endl;
                std::cout << "2. Goal" << std::endl;
                std::cout << "3. Day" << std::endl;
                std::cout << "4. Month" << std::endl;
                std::cout << "5. Year" << std::endl;
                std::cout << "6. Cancel" << std::endl;
                std::cout << "Choice:" << std::endl;

                std::cin >> selection;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } while (validMenuInput(selection, 1, 6) != 1);

            do
            {
                clearScreen();
                std::cout << "Which day(1-7)" << std::endl;
                std::cout << "Choice:" << std::endl;

                std::cin >> day;
            } while (validMenuInput(day, 1, 7) != 1);
            
            clearScreen();
            if (selection == 1)
            {
                std::cout << "Enter new name" << std::endl;
                std::cin >> tempStr;
                ePlan[day].setName(tempStr);
            }
            else if (selection == 2)
            {
                std::cout << "Enter new goal" << std::endl;
                std::cin >> tempInt;
                ePlan[day].setGoal(tempInt);
            }
            else if (selection == 3)
            {
                std::cout << "Enter new day" << std::endl;
                std::cin >> tempInt;
                ePlan[day].setDay(tempInt);
            }
            else if (selection == 4)
            {
                std::cout << "Enter new month" << std::endl;
                std::cin >> tempInt;
                ePlan[day].setMonth(tempInt);
            }
            else if (selection == 5)
            {
                std::cout << "Enter new year" << std::endl;
                std::cin >> tempInt;
                ePlan[day].setYear(tempInt);
            }
            pauseScreen();
            break;

        case EXIT:
            //diet store
            outputStream.open("dietPlans.txt");
            storeWeeklyPlan(outputStream, dPlan);
            outputStream.close();

            //excercise store
            outputStream.open("excercisePlans.txt");
            storeWeeklyPlan(outputStream, ePlan);
            outputStream.close();
            
            std::cout << "Exiting...";

            quit = 1;
            break;
        }
    } while (quit == 0);

}

void FitnessAppWrapper::loadDailyPlan(ifstream& fileStream, DietPlan& plan)
{
    fileStream >> plan;
}

void FitnessAppWrapper::loadWeeklyPlan(ifstream& fileStream, DietPlan weeklyPlan[DAYSINAWEEK])
{
    for (int i = 0; i < DAYSINAWEEK; i++)
    {
        loadDailyPlan(fileStream, weeklyPlan[i]);
    }
}

void FitnessAppWrapper::displayDailyPlan(ostream& fileStream, DietPlan plan)
{
    fileStream << plan;
}

void FitnessAppWrapper::displayWeeklyPlan(ostream& fileStream, DietPlan weeklyPlan[DAYSINAWEEK])
{
    for (int i = 0; i < DAYSINAWEEK; i++)
    {
        displayDailyPlan(fileStream, weeklyPlan[i]);
        //so it does something
        std::cout << std::endl;
    }
}

void FitnessAppWrapper::storeDailyPlan(ofstream& fileStream, DietPlan& plan)
{
    fileStream << plan;
}

void FitnessAppWrapper::storeWeeklyPlan(ofstream& fileStream, DietPlan weeklyPlan[DAYSINAWEEK])
{
    for (int i = 0; i < DAYSINAWEEK; i++)
    {
        storeDailyPlan(fileStream, weeklyPlan[i]);
        //so it does something
        std::cout << std::endl;
    }
}


//excercise plan

void FitnessAppWrapper::loadDailyPlan(ifstream& fileStream, ExcercisePlan& plan)
{
    fileStream >> plan;
}

void FitnessAppWrapper::loadWeeklyPlan(ifstream& fileStream, ExcercisePlan weeklyPlan[DAYSINAWEEK])
{
    ExcercisePlan temp;
    for (int i = 0; i < DAYSINAWEEK; i++)
    {
        loadDailyPlan(fileStream, weeklyPlan[i]);
    }
}

void FitnessAppWrapper::displayDailyPlan(ostream& fileStream, ExcercisePlan plan)
{
    fileStream << plan;
}

void FitnessAppWrapper::displayWeeklyPlan(ostream& fileStream, ExcercisePlan weeklyPlan[DAYSINAWEEK])
{
    for (int i = 0; i < DAYSINAWEEK; i++)
    {
        displayDailyPlan(fileStream, weeklyPlan[i]);
        //so it does something
        std::cout << std::endl;
    }
}

void FitnessAppWrapper::storeDailyPlan(ofstream& fileStream, ExcercisePlan& plan)
{
    fileStream << plan;
}

void FitnessAppWrapper::storeWeeklyPlan(ofstream& fileStream, ExcercisePlan weeklyPlan[DAYSINAWEEK])
{
    for (int i = 0; i < DAYSINAWEEK; i++)
    {
        storeDailyPlan(fileStream, weeklyPlan[i]);
        //so it does something
        std::cout << std::endl;
    }
}
