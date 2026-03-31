#pragma once

#include <iostream>
#include <string>
#include <fstream>

using std::string;

class Node
{
    public:
    string data;
    Node* leftNode;
    Node* rightNode;
    
    Node();
    Node(string newData)
    {
        data = newData;
    }
    ~Node();
    private:

};

class Tree
{
    public:
    void insertNode(string newData);

    //precondition of traversal is root isnt null (i dont wanna rewrite it)
    void inOrderTraversal(Node cur);
    void preOrderTraversal(Node cur);
    void postOrderTraversal(Node cur);
    bool isEmpty();
    void arrToTree(string arr[]);

    private:
    Node* root;    

    void destroyTree();
};