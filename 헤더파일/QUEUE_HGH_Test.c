#include <stdio.h>
#include <stdlib.h>
#include "QUEUE_HGH.h"

enum menu {
    PUSH = 1,
    POP,
    PEEK,
    PRINT,
    EXIT
};

void printMenu();
void inputData(Data *data);
void printData(Data data);

char dataType = FLOAT;

int main()
{
    Queue q;

    QueueInit(&q, dataType);

    while (1) {
        int n;
        Data data;
        
        printMenu();
        scanf("%d", &n);

        switch (n) {
            case PUSH:
                printf("값을 입력하세요: ");
                inputData(&data);
                Enqueue(&q, data);
                break;
            case POP:
                data = Dequeue(&q);
                printData(&data);
                break;
            case PEEK:
                data = Peek(&q);
                printData(&data);
                break;
            case PRINT:
                PrintQueue(&q);
                break;
            case EXIT:
                exit(0);
        }
    }
    
    return 0;
}

void printMenu()
{
    putchar('\n');
    puts("===================");
    puts("1. Enqueue");
    puts("2. Dequeue");
    puts("3. Peek");
    puts("4. Print");
    puts("5. Exit");
    puts("===================");

    printf("메뉴를 선택하세요: ");
}

void inputData(Data *data)
{
    if (dataType == CHAR) scanf("%s", data);
    else if (dataType == SHORT) scanf("%hd", data);
    else if (dataType == INT) scanf("%d", data);
    else if (dataType == FLOAT) scanf("%f", data);
    else scanf("%lf", data);
}

void printData(Data data)
{
    if (dataType == CHAR) printf("Returned data: %s\n", (char*)data);
    else if (dataType == SHORT) printf("Returned data: %hd\n", *(short*)data);
    else if (dataType == INT) printf("Returned data: %d\n", *(int*)data);
    else if (dataType == FLOAT) printf("Returned data: %f\n", *(float*)data);
    else printf("Returned data: %lf\n", *(double*)data);
}