#ifndef ___Stack_KGS
#define ___Stack_KGS

#define sINT 1
#define sDOUBLE 2
#define sCHAR 3

int STACK_TYPE = 0;

#if STACK_TYPE == 2
    typedef struct {
        int max;  // 용량
        int ptr;  // 포인터
        double *stk; // 첫 요소 
    } Stack;

#elif STACK_TYPE == 3
    typedef struct {
        int max;  // 용량
        int ptr;  // 포인터
        char *stk; // 첫 요소 
    } Stack;
#else 
    typedef struct {
        int max;  // 용량
        int ptr;  // 포인터
        int *stk; // 첫 요소 
    } Stack;
#endif


// 초기화
int Init(Stack *s, int max);

// 데이터 추가
int Push(Stack *s, void* x);

// 데이터 꺼내기
int Pop(Stack *s, void *x);

// 데이터 확인
int Peek(const Stack *s, void *x);

// 스택 비우기
void Clear(Stack *s);

// 데이터 개수
int Size(const Stack *s);

// 검색
int Find(const Stack *s, void *x);

// 모든 데이터 출력
void Print(const Stack *s);

// 스택 해제
int Free(Stack *s);

#endif