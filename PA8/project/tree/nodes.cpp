#include "..\tree\tree.hpp"

//node
Node::Node(string newString)
{
    mData = newString;
    mpLeft = nullptr;
    mpRight = nullptr;
}

Node*& Node::getRight()
{
    return mpRight;
}

Node*& Node::getLeft()
{
    return mpLeft;
}

string Node::getData()
{
    return mData;
}

void Node::setRight(Node* other)
{
    mpRight = other;
}

void Node::setLeft(Node* other)
{
    mpLeft = other;
}

void Node::setData(string other)
{
    mData = other;
}


//tnode
//this is what the syntax was for this online honestly i dont know if this is what andy wants
TransactionNode::TransactionNode(string newString, int newInt) : Node(newString)
{
    mUnits = newInt;
}

int TransactionNode::getUnits()
{
    return mUnits;
}

void TransactionNode::setUnits(int newInt)
{
    mUnits = newInt;
}

void TransactionNode::printData()
{
    std::cout << "Type: "<< getData() << ", Units:" << getUnits() << std::endl;
}