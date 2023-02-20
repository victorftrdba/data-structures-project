#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define STACK_LENGTH 5
#define EMPTY (-1)
#define STACK_EMPTY INT_MIN

int mystack[STACK_LENGTH];
int top = EMPTY;

bool push(int value)
{
    if (top >= STACK_LENGTH - 1)
    {
        return false;
    }

    top++;
    mystack[top] = value;
    return true;
}

int pop()
{
    if (top == EMPTY)
    {
        return STACK_EMPTY;
    }

    int result = mystack[top];
    top--;
    return result;
}

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    pop();

    int t;

    while ((t = pop()) != STACK_EMPTY)
    {
        printf("%d \n", t);
    }
}