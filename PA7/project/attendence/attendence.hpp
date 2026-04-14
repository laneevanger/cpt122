#pragma once

#include "..\project\menu\menu.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <ctime>

/*
find current time/date
time_t t = time(0); // get time now
struct tm * now = localtime( & t );
*/

class Data
{
    public:
    //data will need getters and setters so i opted for public over private
    int absences = 0;
    std::stack<std::string> absenceDates;
    int ID = 0;
    std::string fullName = 0;
    std::string email = 0;
    int units = 0;
    std::string program = 0;
    int level = 0;

    private:

};

template <class T>
class Node
{
    public:
    Node(T data);
    ~Node();

    //these are going public too
    T data;
    Node<T>* nextNode;
    private:

};

template <class T>
class List
{
    public:
    List();
    ~List();
    void loadList(std::ifstream& infile);
    void loadList(std::ifstream& infile, std::ifstream& delfile);
    void writeToFile(std::ofstream& outfile);
    void checkAttendance();
    void editAbsences();
    void generateReport(std::ofstream& outfile);
    void generateReport(std::ofstream& outfile, int maxAbsences);

    private:
    Node<T>* headNode;
};