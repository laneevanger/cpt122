#pragma once

#include <iostream>

int main(void)
{
    Base* ptr = new Base; 
 
    ptr -> testFunction ();  // prints "Base class" 
 
    delete ptr; 
 
    ptr = new Derived; 
 
    ptr -> testFunction ();  // prints "Base class" because the base class function is not virtual 
 
    delete ptr; 
 
    return 0; 

}

template< class NODETYPE > class List;  // forward declaration 
 
template<class NODETYPE> 
class ListNode  
{ 
    friend class List< NODETYPE >; // make List a friend 
public: 
    ListNode( const NODETYPE &newData);  // copy constructor 
    NODETYPE getData() const;      // return data in the node 
private: 
    NODETYPE data;                 // data 
    ListNode< NODETYPE > *nextPtr; // next node in the list 
}; 
 
 
template< class NODETYPE > 
class List  
{ 
    public: 
    List();      // constructor 
    ~List();     // destructor 
    void insertAtFront( const NODETYPE &newData ); 
    void insertAtBack( const NODETYPE &newData ); 
    bool removeFromFront( NODETYPE &removedData ); 
    bool removeFromBack( NODETYPE &removedData ); 
    bool isEmpty() const; 

    void print() const; 
private: 
    ListNode< NODETYPE > *firstPtr;  // pointer to first node 
    ListNode< NODETYPE > *lastPtr;   // pointer to last node 
 
    // Utility function to allocate a new node 
    ListNode< NODETYPE > *getNewNode( const NODETYPE &newData ); 
}; 

template< class NODETYPE > 
class Queue : List
{
    public:
    void enqueue();
    void dequeue();
    
    private:

};

using std::cout; 
using std::endl; 
 
class Base 
{ 
    public: 
    virtual void testFunction ();
}; 
 
class Derived : public Base 
{ 
    public: 
    void testFunction (); 
}; 

void Base::testFunction () 
{ 
    cout << "Base class" << endl; 
} 
 
void Derived::testFunction () 
{ 
    cout << "Derived class" << endl; 
} 
 