// 개미 정렬시키고 이동 

#include <stdio.h>
#include <stdlib.h>

typedef struct _Ant
{
    int p;
    char dir;
} Ant;

void print_ant(const int l, const int n, const int *line, const Ant *_ant){
    for (int i = 0; i < l; i++)
        printf("%d ", line[i]);
    puts("");

    for (int i = 0; i < n; i++)
        printf("%d ", _ant[i].p);
    puts("");
}

int ant_move_sync(Ant *a, const int n , int *line, const int end){

    //  개미 같은 곳에 있을 경우
    if (line[a->p] > 1) {
        if (a->dir == 'D')
            a->dir = 'L';
        else
            a->dir = 'D';
    }

    // 줄 끝에 있을 경우
    if (a->p <= 0) {
        a->dir = 'D';
    } else if (a->p >= end-1) {
        a->dir = 'L';
    }
    
    return 0;
}

int main() {
    int l, t;
    int n;
    int *line;

    scanf(" %d %d", &l, &t);
    scanf(" %d", &n);
    l += 1;

    Ant *ant = malloc(sizeof(Ant) * n);
    line = malloc(sizeof(int) * l);

    for (int i = 0; i < n; i++) {
        scanf(" %d %c", &ant[i].p, &ant[i].dir);
        line[ant[i].p] += 1; //개미 번호
    }

    //이동 L D
    while (t--)
    {
        getchar();
        print_ant(l, n, line, ant);
        
        for (int i = 0; i < n; i++) {
            line[ant[i].p] -= 1;

            // 개미 이동
            if (ant[i].dir == 'L'){ // 왼쪽
                    ant[i].p -= 1;
            } else { // 오른쪽
                    ant[i].p += 1;
            }

            line[ant[i].p] += 1;
        }

        for (int i = 0; i < n; i++) {
            ant_move_sync(&ant[i], n, line, l);
        }
    }
        
    
    return 0;
}