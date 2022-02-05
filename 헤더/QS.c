#include <stdio.h>
#include <stdlib.h>
#include "QS.h"


// 초기화
void Init(List *list, int type, int size) {
    list->n = calloc(size, sizeof(Node));
    list->num = list->front = list->rear = 0;
    list->type = type;
    list->size = size;
}

// 데이터 추가
int Push(List *list, void *x) {

    // 가득 차 있을 때
    if (list->num == list->size) {
        return -1;
    } else {
        list->num++;
        list->n[list->rear++].data = x;

        if (list->rear == list->size)
            list->rear = 0;
    }

    return 0;
}

// 데이터 팝, 스택 모드
int SPop(List *list) {

    // 비어 있을 경우
    if (list->num <= 0) {
        return -1;
    } else {
        free(list->n[list->rear-1].data);

        list->num--;
        list->rear--;

        return 0;
    }
}

// 데이터 팝, 큐 모드
int QPop(List *list) {

    // 비어 있을 경우
    if (list->num <= 0) {
        return -1;
    } else {
        free(list->n[list->front].data);

        list->num--;
        list->front++;

        return 0;
    }
}

// 데이터 확인
int Peek(const List *list) {

    // 비어 있을 경우
    if (list->num <= 0) {
        return -1;
    } else {

        // 타입별로 출력
        switch (list->type) {
            case 1: printf("%d\n", *(int *)list->n[list->rear-1].data); break;
            case 2: printf("%lf\n", *(double *)list->n[list->rear-1].data); break;
            case 3: printf("%s\n", (char *)list->n[list->rear-1].data); break;
        }

        return 0;
    }
}


// 모든 데이터 지우기
void Clear(List *list) {
    for (int i = list->front; i < list->rear; i++)  {
        if (list->n[i].data != NULL)
            free(list->n[i].data);   
    }

    list->num = list->front = list->rear = 0;
}

// 데이터 개수
int Size(const List *list) {
    return list->num;
}

// 모든 데이터 출력
void Print(const List *list){
    for (int i = list->front; i < list->rear; i++) {
        printf("[%d]: ", i);

        // 타입별로 출력
        switch (list->type) {
            case 1: printf("%d\n", *(int *)list->n[i].data); break;
            case 2: printf("%lf\n", *(double *)list->n[i].data); break;
            case 3: printf("%s\n", (char *)list->n[i].data); break;
        }
    }
}

// 해체
void Free(List *list) {
    if (list->n != NULL)
        free(list->n); // 메모리 할당된거 삭제
    
    list->num = list->front = list->rear = 0;
}