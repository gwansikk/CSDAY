#include <stdio.h>
#include <stdlib.h>
#include "QUEUE_HGH.h"

void QueueInit(Queue *pqueue, char dataType)
{
    pqueue->dataType = dataType;
    pqueue->front = NULL;
    pqueue->rear = NULL;
}

int IsEmpty(Queue *pqueue)
{
    if (pqueue->rear == NULL)
        return TRUE;
    else
        return FALSE;
}

void Enqueue(Queue *pqueue, Data data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));

    newNode->next = NULL;
    newNode->data = data;

    if (IsEmpty(pqueue)) {
        pqueue->front = newNode;
        pqueue->rear = newNode;
    }
    else {
        pqueue->rear->next = newNode;
        pqueue->rear = newNode;
    }
}

Data Dequeue(Queue *pqueue)
{
    Node *rNode;
    Data rData;

    if (IsEmpty(pqueue)) {
        perror("Queue is Empty.\n");
        exit(-1);
    }
    
    rNode = pqueue->front;
    rData = rNode->data;
    pqueue->front = pqueue->front->next;

    free(rNode);

    return rData;
}

Data Peek(Queue *pqueue)
{
    if (IsEmpty(pqueue)) {
        perror("Queue is Empty.\n");
        exit(-1);
    }

    if (pqueue->dataType == CHAR) return (char*)pqueue->front->data;
    else if (pqueue->dataType == SHORT) return (short*)pqueue->front->data;
    else if (pqueue->dataType == INT) return (int*)pqueue->front->data;
    else if (pqueue->dataType == FLOAT) return (float*)pqueue->front->data;
    else return (double*)pqueue->front->data;
}

void PrintQueue(Queue *pqueue)
{
    Node *node = pqueue->front;

    while (node != NULL) {
        if (pqueue->dataType == CHAR) printf("%s ", (char*)&(node->data));
        else if (pqueue->dataType == SHORT) printf("%hd ", *(short*)&(node->data));
        else if (pqueue->dataType == INT) printf("%d ", *(int*)&(node->data));
        else if (pqueue->dataType == FLOAT) printf("%f ", *(float*)&(node->data));
        else printf("%lf ", *(double*)&(node->data));

        node = node->next;
    }
    putchar('\n');
}