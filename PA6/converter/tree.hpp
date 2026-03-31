#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "..\converter\node.hpp"

//root is A, left is special/numbers 
//right is letters with vowels being right nodes and inbetweens going left
//this assignment doesnt make up translate spaces into morse so it isnt real morse lmao
class BST
{
    public:
    BST();
    ~BST();

    BSTNode* getRoot();

    void createMorseTree(std::ifstream& infile);
    void printTree(BSTNode* cur);

    void printWords(std::ifstream& infile);

    private:
    BSTNode* root;
    void destroy(BSTNode* node);
};