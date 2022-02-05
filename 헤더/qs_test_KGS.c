#include <stdio.h>
#include <stdlib.h>
#include "QS.h"


void PrintMenu();

int main() {
    List stack;
    int* data;
    Init(&stack, INT, 10);

    while (1) {
        int n;
        data = malloc(sizeof(int));

        PrintMenu();
        scanf("%d", &n);

        switch (n) {
            case 1:
                printf("Push: ");
                scanf("%d", data);
                Push(&stack, data);
                break;
            case 2:
                QPop(&stack);
                break;
            case 3:
                Peek(&stack);
                break;
            case 4:
                Print(&stack);
                break;
            case 5:
                Clear(&stack);
                Free(&stack);
                exit(0);
                break;
        }
    }
    
    return 0;
}

void PrintMenu()
{
    putchar('\n');
    puts("===================");
    puts("1. Push");
    puts("2. Pop");
    puts("3. Peek");
    puts("4. Print");
    puts("5. Exit");
    puts("===================");

    printf("Number: ");
}
