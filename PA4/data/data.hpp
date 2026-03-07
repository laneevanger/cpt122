#pragma once

#include <iostream>
#include <string>

//deleted equivelent cpp files because i thought they were unneeded

class DietPlan
{
    public:
        DietPlan();
        ~DietPlan();

        std::string getName()
        {
            return name;
        }

        std::string getGoal()
        {
            return goal;
        }

        //so close to java yet so far
        std::string getDate()
        {
            return std::to_string(month) + "/" + std::to_string(day) + "/" + std::to_string(year);
        }

        std::string setName(std::string input)
        {
            name = input;
        }

        std::string setGoal(std::string input)
        {
            goal = input;
        }

        //lwk just did it for fun
        std::string setDay(int input)
        {
            day = input;
        }
        std::string setMonth(int input)
        {
            month = input;
        }
        std::string setYear(int input)
        {
            year = input;
        }

    private:
        std::string name;
        std::string goal;
        int day;
        int month;
        int year;

};

class ExcercisePlan
{
    public:
        ExcercisePlan();
        ~ExcercisePlan();

        std::string getName()
        {
            return name;
        }

        std::string getGoal()
        {
            return goal;
        }

        std::string getDate()
        {
            return std::to_string(month) + "/" + std::to_string(day) + "/" + std::to_string(year);
        }

        int getDay()
        {
            return day;
        }

        int getMonth()
        {
            return month;
        }

        int getYear()
        {
            return year;
        }

        std::string setName(std::string input)
        {
            name = input;
        }

        std::string setGoal(std::string input)
        {
            goal = input;
        }

        std::string setDay(int input)
        {
            day = input;
        }
        std::string setMonth(int input)
        {
            month = input;
        }
        std::string setYear(int input)
        {
            year = input;
        }

        void operator=(const ExcercisePlan &other) const
        {
            //this->name = other->name;
        }

    private:
        std::string name;
        std::string goal;
        int day;
        int month;
        int year;
        
};