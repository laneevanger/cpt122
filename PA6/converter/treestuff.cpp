#include "..\converter\tree.hpp"

//node

BSTNode::BSTNode()
{
    letter = ' ';
    morse = "";
    leftptr = nullptr;
    rightptr = nullptr;
}

BSTNode::~BSTNode() {}

//honestly no clue why i didnt just override string instead of file
std::ifstream& operator>>(std::ifstream& input, BSTNode& curNode)
{
    string line;
    string letter;
    string morse;

    std::getline(input, line);

    std::istringstream morseTok(line);

    morseTok >> letter;
    morseTok >> morse;

    curNode.letter = letter[0];
    curNode.morse = morse;

    input.ignore();

    return input;
}

bool BSTNode::operator>(const BSTNode& other)
{
    if(letter > other.letter)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool BSTNode::operator<(const BSTNode& other)
{
    if(letter < other.letter)
    {
        return true;
    }
    else
    {
        return false;
    }
}


//tree

BST::BST()
{
    root = nullptr;
}

BST::~BST()
{
    destroy(root);
}

void BST::destroy(BSTNode* node)
{
    if(node != nullptr)
    {
        destroy(node->leftptr);
        destroy(node->rightptr);
        delete node;
    }
}

BSTNode* BST::getRoot()
{
    return root;
}

//idk how balanced its supposed to be but rn its 12(+root) left, 26 right
                                     //and i feel like thats fine
                                     //like its within 1 2^n so i think thats 1 tier
//right sides a little grosser than i initially realized
                              //but like its mentally appealing so im running with it
void BST::createMorseTree(std::ifstream& infile)
{
    BSTNode* curNode;
    BSTNode* lastNode;
    BSTNode* newNode = new BSTNode;

    //assumes data on every line and proper formatting (good enough)
    while(infile >> *newNode)
    {   
        if(root != nullptr)
        {
            curNode = root;
            lastNode = root;
            do
            {
                if(*curNode < *newNode)
                {
                    if(curNode->rightptr != nullptr)
                    {
                        lastNode = curNode;
                        curNode = curNode->rightptr; 
                    }
                    else
                    {
                        lastNode = curNode;
                        curNode = curNode->rightptr;  
                        lastNode->rightptr = newNode;
                    }

                }
                else
                {
                    if(curNode->leftptr != nullptr)
                    {
                        lastNode = curNode;
                        curNode = curNode->leftptr; 
                    }
                    else
                    {
                        lastNode = curNode;
                        curNode = curNode->leftptr;
                        lastNode->leftptr = newNode;
                    }
                }
            }while(curNode != nullptr);

        }
        else
        {
            root = newNode;
        }
        newNode = new BSTNode;
    }
    delete newNode;
}

//stole this from my lab, changed it to only give new lines after end of branches
void BST::printTree(BSTNode* cur)
{
    std::cout << cur->letter + " ";
    if(cur->leftptr != nullptr)
    {
        printTree(cur->leftptr);
    }
    else
    {
        std::cout << std::endl;
    }
    if(cur->rightptr != nullptr)
    {
        printTree(cur->rightptr);
    }
}

//wont print characters not in tree
void BST::printWords(std::ifstream& infile)
{
    BSTNode* curNode;
    string curWord;

    while(std::getline(infile, curWord))
    {
        std::cout << curWord + "- ";
        for(int i = 0; i < curWord.length(); i++)
        {
            curNode = root;
            while(curNode != nullptr)
            {
                if(std::toupper(curWord[i]) == curNode->letter)
                {
                    std::cout << curNode->morse + " ";
                    break;
                }
                else if(curWord[i] > curNode->letter)
                {
                    curNode = curNode->rightptr;
                }
                    
                else
                {
                    curNode = curNode->leftptr;
                }
            }
        }
        std::cout << std::endl;
    }       
}