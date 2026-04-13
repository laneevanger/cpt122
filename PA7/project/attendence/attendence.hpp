#pragma once

#include <iostream>
#include <string>
#include <istream>
#include <stack>

class Data
{
    public:
    
    private:
    int absences;
    std::stack<std::string> absenceDates;
};

template <class T>
class Node
{
    public:

    private:
    T data;
    Node<T>* nextNode;
};