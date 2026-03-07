#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::ifstream;
using std::ofstream;
using std::ios;

#include "app.hpp"
#include "data.hpp"

#define MAGICSTRLEN 150
#define DAYSINAWEEK 7

enum Menu
{
	LOAD = 1,
	LOADWDP,
	LOADWEP,
	STOREWDP,
	STOREWEP,
	DISPLAYWDP,
	DISPLAYWEP,
	EDITDDP,
	EDITDEP,
	SHUFFLE,
	EXIT
};

//make your enum for the switch

class FitnessAppWrapper
{
    public:
        void printMenu();
        bool validMenuInput(int input, int lowerRange, int higherRange);
        void runApp();

    private:
        std::string name[MAGICSTRLEN];
        ExcercisePlan ePlan[DAYSINAWEEK];
        DietPlan dPlan[DAYSINAWEEK];

        ifstream mInputStream;
        ofstream mOutputStream;

        void loadDailyPlan(ifstream &fileStream, DietPlan &plan);
        void loadWeeklyPlan(ifstream &fileStream, DietPlan weeklyPlan[]);
        void displayWeeklyPlan();
        void storeDailyPlan(ofstream &fileStream, DietPlan &plan);
        void storeWeeklyPlan(ofstream &fileStream, DietPlan weeklyPlan[]);

        void loadDailyPlan(ifstream &fileStream, ExcercisePlan &plan);
        void loadWeeklyPlan(ifstream &fileStream, ExcercisePlan weeklyPlan[]);
        void displayWeeklyPlan();
        void storeDailyPlan(ofstream &fileStream, ExcercisePlan &plan);
        void storeWeeklyPlan(ofstream &fileStream, ExcercisePlan weeklyPlan[]);
};

//needs extraction and insertion operators
//overload equals