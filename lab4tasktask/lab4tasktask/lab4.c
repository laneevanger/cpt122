#include "lab4.h"
#include <stdlib.h>
#include <assert.h>
#include <float.h>

Stack stack_create()
{
    Stack s;
    s.top = NULL;
    s.size = 0;
    return s;
}

void stack_push(Stack* s, int value)
{
    assert(s != NULL);

    StackNode* n = malloc(sizeof(StackNode));
    assert(n != NULL);

    n->value = value;
    n->next = s->top;

    s->top = n;
    s->size++;
}

int stack_peek(const Stack* s)
{
    assert(s != NULL);
    if (s->size == 0)
    {
        // Stack is empty, return infinity
        return DBL_MAX;
    }

    assert(s->top != NULL);
    return s->top->value;
}

int stack_pop(Stack* s)
{
    assert(s != NULL);
    if (s->size == 0)
    {
        // Stack is empty, return infinity
        return DBL_MAX;
    }

    StackNode* n = s->top;
    int value = n->value;
    s->top = n->next;
    s->size--;

    free(n);
    return value;
}

bool stack_empty(const Stack* s)
{
    assert(s != NULL);
    return s->size == 0;
}

void free_stack(Stack* s)
{
    while (stack_pop(s) != DBL_MAX);
}