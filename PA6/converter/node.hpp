#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>

using std::string;

class BSTNode
{
    public:
    BSTNode();
    ~BSTNode();
    
    bool operator>(const BSTNode& other);
    bool operator<(const BSTNode& other);

    //i needed getters and setters so i made them [all] public
    char letter;
    string morse;
    BSTNode* leftptr;
    BSTNode* rightptr;
    private:
};