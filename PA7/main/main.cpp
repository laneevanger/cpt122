#include "..\project\attendence\attendence.hpp"

int main(void)
{
    int stop = 0;
    int menuChoice = 0;
    List<Data> masterList;

    while(stop == 0)
    {
        do
        {
            system("cls");
            printMenu();
            std::cout << "Choice:" << std::endl;
            std::cin >> menuChoice;
        } while(!isMenuInput(menuChoice, 1, 7));
        
        switch(menuChoice)
        {
        case LOADCLASS:
        {
            std::ifstream infile("classList.csv");
            std::ifstream delfile("masterList.csv");
            masterList.loadList(infile, delfile);
            delfile.close();
            infile.close();
            system("cls");
            std::cout << "Loaded" << std::endl;
            break;
        }
        case LOADMASTER:
        {
            std::ifstream infile("masterList.csv");
            masterList.loadList(infile);
            infile.close();
            break;
        }
        case STOREMASTER:
        {
            std::ofstream outfile("masterList.csv");
            masterList.writeToFile(outfile);
            outfile.close();
            break;
        }
        case MARKABSENCES:
        {
            masterList.checkAttendance();
            break;
        }
        case EDIT:
        {
            masterList.editAbsences();
            break;
        }
        case REPORT:
        {
            int reportChoice = 0;
            do
            {
                system("cls");
                std::cout << "1: All students" << std::endl;
                std::cout << "2: Students over x absences" << std::endl;
                std::cout << "Choice:" << std::endl;
                std::cin >> reportChoice;
            } while(!isMenuInput(reportChoice, 1, 2));

            if(reportChoice == 1)
            {
                std::ofstream outfile("report.txt");
                masterList.generateReport(outfile);
                outfile.close();
            }
            else
            {
                int num;
                std::cout << "Above how many absences: " << std::endl;
                std::cin >> num;
                std::ofstream outfile("report.txt");
                masterList.generateReport(outfile, num);
                outfile.close();
            }
            break;
        }
        case EXIT:
        {
            stop = 1;
            break;
        }
        }
    }

}