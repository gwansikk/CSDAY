// O(n)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int max;
    int ptr;
    int *stk;
} IntStack;

int InitStack(IntStack *s, int max){
    s->ptr = 0;
    
    if ((s->stk = (int*)calloc(max, sizeof(int))) == NULL) {
        s->max = 0;
        return -1;   
    }

    s->max = max;
    return 0;
}

int Push(IntStack *s, int x){
    if(s->ptr >= s->max)
        return -1;

    s->stk[s->ptr++] = x;
    return 0;
}

int Pop(IntStack *s, int *x){
    if (s->ptr <= 0)
        return -1;
    
    *x = s->stk[s->ptr-1];
    s->ptr--;
    return 0;
}

int Size(const IntStack *s){
    return s->ptr;
}

int Empty(const IntStack *s){
    return (s->ptr <= 0);
}

int Top(const IntStack *s){
    if (s->ptr <= 0)
        return -1;

    return s->stk[s->ptr-1];
}


int main(){
    IntStack s;
    int n, x;
    char exec[6];

    scanf(" %d", &n);

    InitStack(&s, n);

    while (n--){
        scanf(" %s", exec);

        // 푸쉬
        if (strcmp(exec, "push") == 0){
            scanf(" %d", &x);
            Push(&s, x);
        }
        // 팝
        else if (strcmp(exec, "pop") == 0){
            if(Pop(&s, &x) == -1 )
                puts("-1");
            else 
                printf("%d\n", x);
        }
        // 사이즈
        else if (strcmp(exec, "size") == 0){
            printf("%d\n", Size(&s));
        }
        // 비어있는지
        else if (strcmp(exec, "empty") == 0){
            printf("%d\n", Empty(&s));
        }
        // 탑
        else if (strcmp(exec, "top") == 0){
            int temp = Top(&s);

            if(temp == -1)
                puts("-1");
            else 
                printf("%d\n", temp);
        }

    }
    
    //free +
    return 0;
}