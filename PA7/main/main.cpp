#include "..\project\menu\menu.hpp"
#include "..\project\attendence\attendence.hpp"

int main(void)
{
    int stop = 0;
    int menuChoice = 0;

    while(stop == 0)
    {
        system("cls");
        printMenu();
        do
        {
            system("cls");
            printMenu();
            std:: cout << "Choice:" << std::endl;
            std::cin >> menuChoice;
        } while(!isMenuInput(menuChoice, 1, 7));
        
        switch (menuChoice)
        {
        case LOADCLASS:
            break;
        
        case LOADMASTER:
            break;

        case STOREMASTER:
            break;

        case DISPLAYMASTER:
            break;
        
        case EDIT:
            break;

        case REPORT:
            break;

        case EXIT:
            stop = 1;
            break;
        }
    }


}