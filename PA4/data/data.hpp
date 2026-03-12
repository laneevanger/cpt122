#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <sstream>

using std::ifstream;
using std::ofstream;
using std::ostream;
using std::ios;

//deleted equivelent cpp files because i thought they were unneeded

class DietPlan
{
public:
    DietPlan()
    {
        name = ("");
        goal = 0;
        day = 0;
        month = 0;
        year = 0;
    }
    ~DietPlan()
    {

    }

    friend std::ostream& operator<<(std::ostream& output, const DietPlan& plan)
    {
        output << plan.getName() << "\n" << plan.getGoal() << "\n" << plan.getDate() << "\n\n";
        return output;
    }

    friend std::ifstream& operator>>(std::ifstream& input, DietPlan& plan)
    {
        std::string name;
        std::string date;
        std::string calories;
        std::string day;
        std::string month;
        std::string year;


        std::getline(input, name);
        std::getline(input, calories);
        std::getline(input, date);

        std::istringstream dateLine(date);

        getline(dateLine, day, '/');
        getline(dateLine, month, '/');
        getline(dateLine, year);

        plan.setName(name);
        plan.setGoal(std::stoi(calories));
        plan.setDay(std::stoi(day));
        plan.setMonth(std::stoi(month));
        plan.setYear(std::stoi(year));

        input.ignore();

        return input;
    }

    std::string getName() const
    {
        return name;
    }

    int getGoal() const
    {
        return goal;
    }

    //so close to java yet so far
    std::string getDate() const
    {
        return std::to_string(month) + "/" + std::to_string(day) + "/" + std::to_string(year);
    }

    void setName(std::string input)
    {
        name = input;
    }

    void setGoal(int input)
    {
        goal = input;
    }

    //lwk just did it for fun
    void setDay(int input)
    {
        day = input;
    }
    void setMonth(int input)
    {
        month = input;
    }
    void setYear(int input)
    {
        year = input;
    }

    void operator=(const DietPlan& other)
    {
        name = other.name;
        goal = other.goal;
        day = other.day;
        month = other.month;
        year = other.year;
    }

private:
    std::string name;
    int goal;
    int day;
    int month;
    int year;

};

class ExcercisePlan
{
public:

    ExcercisePlan()
    {
        name = "";
        goal = 0;
        day = 0;
        month = 0;
        year = 0;
    }
    ~ExcercisePlan()
    {

    }

    friend std::ostream& operator<<(std::ostream& output, const ExcercisePlan& plan)
    {
        output << plan.getName() << "\n" << plan.getGoal() << "\n" << plan.getDate() << "\n\n";
        return output;
    }
    friend std::ifstream& operator>>(std::ifstream& input, ExcercisePlan& plan)
    {
        std::string name;
        std::string date;
        std::string calories;
        std::string day;
        std::string month;
        std::string year;


        std::getline(input, name);
        std::getline(input, calories);
        std::getline(input, date);

        std::istringstream dateLine(date);

        getline(dateLine, day, '/');
        getline(dateLine, month, '/');
        getline(dateLine, year);

        plan.setName(name);
        plan.setGoal(std::stoi(calories));
        plan.setDay(std::stoi(day));
        plan.setMonth(std::stoi(month));
        plan.setYear(std::stoi(year));

        input.ignore();

        return input;
    }

    std::string getName() const
    {
        return name;
    }
     
    int getGoal() const
    {
        return goal;
    }

    std::string getDate() const
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

    void setName(std::string input)
    {
        name = input;
    }

    void setGoal(int input)
    {
        goal = input;
    }

    void setDay(int input)
    {
        day = input;
    }
    void setMonth(int input)
    {
        month = input;
    }
    void setYear(int input)
    {
        year = input;
    }

    void operator=(const ExcercisePlan& other)
    {
        name = other.name;
        goal = other.goal;
        day = other.day;
        month = other.month;
        year = other.year;
    }

private:
    std::string name;
    int goal;
    int day;
    int month;
    int year;

};