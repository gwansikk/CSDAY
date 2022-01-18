#ifndef __STACK_HGH_H__
#define __STACK_HGH_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct node
{
    Data data;
    struct node *next;
} Node;

typedef struct
{
    Node *head;
} Stack;

void StackInit(Stack *pstack);
int IsEmpty(Stack *pstack);
void Push(Stack *pstack, Data data);
Data Pop(Stack *pstack);
Data Peek(Stack *pstack);
void PrintStack(Stack *pstack);

#endif