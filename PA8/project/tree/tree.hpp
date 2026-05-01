#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using std::string;

class Node
{
    public:
    Node() = default;
    Node(string newString);
    virtual ~Node() = default;

    virtual void printData() = 0;

    Node*& getRight();
    Node*& getLeft();
    string getData();

    void setRight(Node* other);
    void setLeft(Node* other);
    void setData(string other);

    protected:
    Node* mpLeft;
    Node* mpRight;  
    string mData; 
};

class TransactionNode : public Node
{
    public:
    TransactionNode() = default;
    TransactionNode(string newString, int newInt);
    ~TransactionNode() override = default;

    int getUnits();
    void setUnits(int newInt);

    void printData() override;

    private:
    
    int mUnits;
};

class BST
{
    public:
    BST();
    ~BST();

    Node* getRoot();
    void setRoot(Node* newRoot);

    void insert(string type, int units);
    void inOrderTraversal();

    TransactionNode& findSmallest();
    TransactionNode& findLargest();

    private:
    Node* mpRoot;

    void destroyTree(Node* root);
    void insert(string type, int units, Node*& root);
    void inOrderTraversal(Node* root);

};

class DataAnalysis
{
    public:
    void runAnalysis();
    
    private:
    BST mTreeSold;
    BST mTreePurchased;
    std::ifstream mCsvStream;
    void openFile();
    void closeFile();
    void readFile();
    void printExtremes();
    void displayTrends();
};