/* 커서 연결 리스트 for 스택, 큐 헤더 */
#ifndef ___QS
#define ___QS

// - 설정 -
#define Null -1
#define INT 1
#define DOUBLE 2
#define CHAR 3
// --------

// 노드
typedef struct __node{
    void *data;
} Node;

// 연결
typedef struct {
    Node *n; // 본체, 동적할당
    int front;
    int rear;
    int type;
    int size;
    int num;
} List;

// 초기화
void Init(List *list, int type, int size);

// 데이터 추가
int Push(List *list, void *x);

// 데이터 팝, 스택 모드
int SPop(List *list);

// 데이터 팝, 큐 모드
int QPop(List *list);

// 데이터 확인
int Peek(const List *list);

// 모든 데이터 지우기
void Clear(List *list);

// 데이터 개수
int Size(const List *list);

// 모든 데이터 출력
void Print(const List *list);

// 해체
void Free(List *list);

#endif