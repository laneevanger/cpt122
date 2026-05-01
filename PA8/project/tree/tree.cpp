#include "..\tree\tree.hpp"

//bst
BST::BST()
{
    mpRoot = nullptr;
}

BST::~BST()
{
    destroyTree(mpRoot);
}

Node* BST::getRoot()
{
    return mpRoot;
}

void BST::setRoot(Node* newRoot)
{
    mpRoot = newRoot;
}

//public one
void BST::insert(string type, int units)
{
    insert(type, units, mpRoot);
}

//public one
void BST::inOrderTraversal()
{
    inOrderTraversal(mpRoot);
}

TransactionNode& BST::findSmallest()
{
    Node* cur = mpRoot;
    while (cur->getLeft() != nullptr)
    {
        cur = cur->getLeft();
    }
    
    return dynamic_cast<TransactionNode&>(*cur);
}

TransactionNode& BST::findLargest()
{
    Node* cur = mpRoot;
    while (cur->getRight() != nullptr)
    {
        cur = cur->getRight();
    }
    
    return dynamic_cast<TransactionNode&>(*cur);
}

void BST::destroyTree(Node* root)
{
    if (root != nullptr)
    {
        destroyTree(root->getLeft());
        destroyTree(root->getRight());
        delete root;
    }
}

//private one
void BST::insert(string type, int units, Node*& curNode)
{
    if (curNode == nullptr)
    {
        curNode = new TransactionNode(type, units);
    }
    else if (units < dynamic_cast<TransactionNode*>(curNode)->getUnits())
    {
        insert(type, units, curNode->getLeft());
    }
    else
    {
        insert(type, units, curNode->getRight());
    }
}

//private one
void BST::inOrderTraversal(Node* root)
{
    if (root != nullptr)
    {
        inOrderTraversal(root->getLeft());
        root->printData();
        inOrderTraversal(root->getRight());
    }
}


//data analysis
void DataAnalysis::runAnalysis()
{
    openFile();
    readFile();

    std::cout << "Sold:" << std::endl;
    mTreeSold.inOrderTraversal();
    std::cout << "Purchased:" << std::endl;
    mTreePurchased.inOrderTraversal();

    std::cout << "Trends:" << std::endl;
    displayTrends();

    closeFile();
}

void DataAnalysis::openFile()
{
    mCsvStream.open("datacopy.csv");
}

void DataAnalysis::closeFile()
{
    mCsvStream.close();
}

void DataAnalysis::readFile()
{
    string line;

    //header
    std::getline(mCsvStream, line);

    while(std::getline(mCsvStream, line))
    {
        std::string tok;
        std::string newData;
        int newUnits;
        std::stringstream wordStream(line);

        std::getline(wordStream, tok, ',');
        newUnits = stoi(tok);

        std::getline(wordStream, tok, ',');
        newData = tok;

        std::getline(wordStream, tok, '\n');
        if(tok == "Purchased")
        {
            mTreePurchased.insert(newData, newUnits); 
        }
        else
        {
            mTreeSold.insert(newData, newUnits);
        }
    }

}

void DataAnalysis::displayTrends()
{
    std::cout << "Most sold: " << std::endl;
    mTreeSold.findLargest().printData();
    std::cout << "Least sold: " << std::endl;
    mTreeSold.findSmallest().printData();
    std::cout << "Most purchased: " << std::endl;
    mTreePurchased.findLargest().printData();
    std::cout << "Least purchased: " << std::endl;
    mTreePurchased.findSmallest().printData();
}