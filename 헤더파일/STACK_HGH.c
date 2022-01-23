#include <stdio.h>
#include <stdlib.h>
#include "STACK_HGH.h"

void StackInit(Stack *pstack, char type)
{
    pstack->type = type;
    pstack->head = NULL;
}

int IsEmpty(Stack *pstack)
{
    if (pstack->head == NULL)
        return TRUE;
    else
        return FALSE;
}

void Push(Stack *pstack, Data data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = pstack->head;

    pstack->head = newNode;
}

Data Pop(Stack *pstack)
{
    Node* rNode;
    Data rData;

    if (IsEmpty(pstack)) {
        perror("Stack is empty.\n");
        exit(-1);
    }

    rNode = pstack->head;
    rData = Peek(pstack);

    pstack->head = pstack->head->next;
    free(rNode);

    return rData;
}

Data Peek(Stack *pstack)
{
    if (IsEmpty(pstack)) {
        perror("Stack is empty.\n");
        exit(-1);
    }
    
    if (pstack->type == CHAR) return (char*)pstack->head->data;
    else if (pstack->type == SHORT) return (short*)pstack->head->data;
    else if (pstack->type == INT) return (int*)pstack->head->data;
    else if (pstack->type == FLOAT) return (float*)pstack->head->data;
    else return (double*)pstack->head->data;
}

void PrintStack(Stack *pstack)
{
    Node* node = pstack->head;
    
    if (IsEmpty(pstack)) return;

    while (1) {
        if (pstack->type == CHAR) printf("%s ", (char*)&(node->data));
        else if (pstack->type == SHORT) printf("%hd ", *(short*)&(node->data));
        else if (pstack->type == INT) printf("%d ", *(int*)&(node->data));
        else if (pstack->type == FLOAT) printf("%f ", *(float*)&(node->data));
        else printf("%lf ", *(double*)&(node->data));

        if (node->next == NULL) break;
        node = node->next;
    }
    putchar('\n');

    free(node);
}