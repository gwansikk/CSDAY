#ifndef __STACK_HGH_H__
#define __STACK_HGH_H__

#define TRUE 1
#define FALSE 0

#define CHAR 0
#define SHORT 1
#define INT 1
#define LONG 1
#define FLOAT 2
#define DOUBLE 3

typedef void* Data;

typedef struct node
{
    Data data;
    struct node *next;
} Node;

typedef struct
{
    char type;
    Node *head;
} Stack;

void StackInit(Stack *pstack, char type);
int IsEmpty(Stack *pstack);
void Push(Stack *pstack, Data data);
Data Pop(Stack *pstack);
Data Peek(Stack *pstack);
void PrintStack(Stack *pstack);

#endif