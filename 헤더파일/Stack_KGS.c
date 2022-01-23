#include <stdio.h>
#include <stdlib.h>
#include "Stack_KGS.h"

// 초기화
int Init(Stack *s, int max) {
    s->ptr = 0;

    if      (STACK_TYPE == 1) s->stk = calloc(max, sizeof(int));
    else if (STACK_TYPE == 2) s->stk = calloc(max, sizeof(double));
    else if (STACK_TYPE == 3) s->stk = calloc(max, sizeof(char));

    s->max = max;

    return 0;
}

// 데이터 추가
int Push(Stack *s, void* x) {

    if (s->ptr >= s->max)
        return -1;

    if      (STACK_TYPE == 1) s->stk[s->ptr++] = (int *)x;
    else if (STACK_TYPE == 2) s->stk[s->ptr++] = (double*)x;
    else if (STACK_TYPE == 3) s->stk[s->ptr++] = (char*)x;

    return 0;
}

// 데이터 꺼내기
int Pop(Stack *s, void *x) {
    if (s->ptr <= 0)
        return -1;

    x = s->stk[s->ptr--];

    return 0;
}

// 데이터 확인
int Peek(const Stack *s, void *x) {
    if (s->ptr <= 0)
        return -1;
    
    x = s->stk[s->ptr - 1];
    
    return 0;
}

// 스택 비우기
void Clear(Stack *s) {
    s->ptr = 0;
}

// 데이터 개수
int Size(const Stack *s) {
    return s->ptr;
}

// 검색
int Find(const Stack *s, void *x) {
    int i;

    for (i = s->ptr - 1; i >= 0; i--)
        if(s->stk[i] == x)
            return i;
    return -1;
}

// 모든 데이터 출력
void Print(const Stack *s) {
    int i;

    for (int i = 0; i < s->ptr; i++)
        printf("%d ", s->stk[i]);
    putchar('\n');
}

// 스택 해제
int Free(Stack *s) {
    if (s->stk != NULL)
        free(s->stk);
    s->max = s->ptr = 0;
}