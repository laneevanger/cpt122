#include "bst.hpp"

void Tree::insertNode(string newData)
{
    Node* cur = root;
    Node* head;
    Node* newNode = new Node(newData);
    newNode->data = newData;

    if(root == nullptr)
    {
        root = newNode;
    }
    else
    {
        while(cur != nullptr)
        {
            if(cur->data > newData)
            {
                head = cur;
                cur = cur->leftNode;
            }
            else
            {
                head = cur;
                cur = cur->rightNode;
            }
        }
        if(head->data > newData)
        {
            head->leftNode = newNode;
        }
        else
        {
            head->rightNode = newNode;
        }
    }

}
void Tree::inOrderTraversal(Node cur)
{
    if(cur.leftNode != nullptr)
    {
        inOrderTraversal(*(cur).leftNode);
    }
    std::cout << cur.data << std::endl;
    if(cur.rightNode != nullptr)
    {
        inOrderTraversal(*(cur).rightNode);
    }
}
void Tree::preOrderTraversal(Node cur)
{
    std::cout << cur.data << std::endl;
    if(cur.leftNode != nullptr)
    {
        preOrderTraversal(*(cur).leftNode);
    }
    if(cur.rightNode != nullptr)
    {
        preOrderTraversal(*(cur).rightNode);
    }

}
void Tree::postOrderTraversal(Node cur)
{
    if(cur.leftNode != nullptr)
    {
        postOrderTraversal(*(cur).leftNode);
    }
    if(cur.rightNode != nullptr)
    {
        postOrderTraversal(*(cur).rightNode);
    }
    std::cout << cur.data << std::endl;
}
bool Tree::isEmpty()
{
    if(root == nullptr)
    {
        return 0;
    }
    return 1;
}

void Tree::arrToTree(string arr[])
{
    for(int i = 0; i < sizeof(arr); i++)
    {
        insertNode(arr[i]);
    }

    inOrderTraversal(*root);
}