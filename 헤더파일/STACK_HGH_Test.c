#include <stdio.h>
#include "STACK_HGH.h"

enum menu {
    PUSH = 1,
    POP,
    PEEK,
    PRINT
};

void printMenu();
void inputData(Data *data);
void printData(Data data);

char dataType = CHAR;

int main()
{
    Stack stk;

    StackInit(&stk, dataType);

    while (1) {
        int n;
        Data data;
        
        printMenu();
        scanf("%d", &n);
        if (n == -9999) break;

        switch (n) {
            case PUSH:
                printf("값을 입력하세요: ");
                inputData(&data);
                Push(&stk, data);
                break;
            case POP:
                data = Pop(&stk);
                printData(&data);
                break;
            case PEEK:
                data = Peek(&stk);
                printData(&data);
                break;
            case PRINT:
                PrintStack(&stk);
                break;
        }
    }
    
    return 0;
}

void printMenu()
{
    putchar('\n');
    puts("===================");
    puts("1. Push");
    puts("2. Pop");
    puts("3. Peek");
    puts("4. Print");
    puts("===================");

    printf("메뉴를 선택하세요(종료: -9999): ");
}

void inputData(Data *data)
{
    if (dataType == CHAR) scanf("%s", data);
    else if (dataType == INT) scanf("%d", data);
    else if (dataType == FLOAT) scanf("%f", data);
    else scanf("%lf", data);
}

void printData(Data data)
{
    if (dataType == CHAR) printf("Returned data: %s\n", (char*)data);
    else if (dataType == INT) printf("Returned data: %d\n", *(int*)data);
    else if (dataType == FLOAT) printf("Returned data: %f\n", *(float*)data);
    else printf("Returned data: %lf\n", *(double*)data);
}