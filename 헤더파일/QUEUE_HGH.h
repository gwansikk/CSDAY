#ifndef __QUEUE_HGH_H__
#define __QUEUE_HGH_H__

#define TRUE 1
#define FALSE 0

#define CHAR 0
#define SHORT 1
#define INT 2
#define LONG 2
#define FLOAT 3
#define DOUBLE 4

typedef void* Data;

typedef struct node
{
    Data data;
    struct node *next;
} Node;

typedef struct
{
    char dataType;
    Node *front;
    Node *rear;
} Queue;

void QueueInit(Queue *pqueuem, char dataType);
int IsEmpty(Queue *pqueue);
void Enqueue(Queue *pqueue, Data data);
Data Dequeue(Queue *pqueue);
Data Peek(Queue *pqueue);
void PrintQueue(Queue *pqueue);

#endif