#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
//for clear screen
#include <cstdlib>

using std::ifstream;
using std::ofstream;
using std::ostream;
using std::ios;

#include "data.hpp"

#define MAGICSTRLEN 150
#define DAYSINAWEEK 7

enum Menu
{
    LOADWDP = 1,
    LOADWEP,
    STOREWDP,
    STOREWEP,
    DISPLAYWDP,
    DISPLAYWEP,
    EDITDDP,
    EDITDEP,
    EXIT
};

class FitnessAppWrapper
{
public:
    FitnessAppWrapper()
    {

    }
    void printMenu();
    bool validMenuInput(int input, int lowerRange, int higherRange);
    void runApp();

    //took these off gemini because idk how else to do this
    void clearScreen() 
    {
    #ifdef _WIN32
        std::system("cls"); // Command for Windows
    #else
        // Assume POSIX or other systems
        std::system("clear"); // Command for Linux/macOS
    #endif
    }
    void pauseScreen()
    {
        std::cout << "Press Enter to continue...";
        std::cin.get();
    }

private:
    DietPlan dPlan[DAYSINAWEEK];
    ExcercisePlan ePlan[DAYSINAWEEK];

    //diet

    void loadDailyPlan(ifstream& fileStream, DietPlan& plan);
    void loadWeeklyPlan(ifstream& fileStream, DietPlan weeklyPlan[DAYSINAWEEK]);
    void displayDailyPlan(ostream& fileStream, DietPlan plan);
    void displayWeeklyPlan(ostream& fileStream, DietPlan weeklyPlan[DAYSINAWEEK]);
    void storeDailyPlan(ofstream& fileStream, DietPlan& plan);
    void storeWeeklyPlan(ofstream& fileStream, DietPlan weeklyPlan[DAYSINAWEEK]);

    //excercise


    void loadDailyPlan(ifstream& fileStream, ExcercisePlan& plan);
    void loadWeeklyPlan(ifstream& fileStream, ExcercisePlan weeklyPlan[DAYSINAWEEK]);
    void displayDailyPlan(ostream& fileStream, ExcercisePlan plan);
    void displayWeeklyPlan(ostream& fileStream, ExcercisePlan weeklyPlan[DAYSINAWEEK]);
    void storeDailyPlan(ofstream& fileStream, ExcercisePlan& plan);
    void storeWeeklyPlan(ofstream& fileStream, ExcercisePlan weeklyPlan[DAYSINAWEEK]);
};
