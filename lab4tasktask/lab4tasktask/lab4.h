#ifndef STACK_H
#define STACK_H

#include <stddef.h>
#include <stdbool.h>

typedef struct stackNode
{
    int value;
    struct stackNode* next;
} StackNode;

typedef struct stack
{
    StackNode* top;
    int size;
} Stack;

/// @brief Initializes a stack with no elements and sets the top pointer to NULL.
Stack stack_create();

/// @brief Adds a new element to the top of the stack. The value is stored on the heap,
///        and the top pointer is updated to point to the new node.
///        The size of the stack is incremented by one.
///
/// @param s A pointer to the stack to which the value will be added.
/// @param value The double value to be added to the stack.
void stack_push(Stack* s, int value);

/// @return The value of the top element of the stack without removing it. Returns DBL_MAX if the stack is empty.
int stack_peek(const Stack* s);

/// @brief Removes the top element from the stack and returns its value.
///        The top pointer is updated to point to the next node, and the size of the stack is decremented by one.
///        The memory allocated for the removed node is freed.
///
/// @param s A pointer to the stack from which the top element will be removed.
/// @return The double value of the removed top element.
int stack_pop(Stack* s);

/// @brief Checks if the stack is empty.
/// @param s A pointer to the stack to be checked.
/// @return true if the stack is empty, false otherwise.
bool stack_empty(const Stack* s);

/// @brief Frees all stack nodes and the stack itself.
/// @param s A pointer to the stack to be freed.
void free_stack(Stack* s);

#endif //STACK_H