// O(n^2)

#include <stdio.h>
#include <stdlib.h>
#define SIZE 26

int GP[SIZE][SIZE];
int CNT = 0;
int SUM = 0;
int XDIR[4] = {-1, 1, 0, 0};
int YDIR[4] = {0, 0, -1, 1};


int compare(const void *a, const void *b) {
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 < num2)
        return -1;
    
    if (num1 > num2)
        return 1;
    
    return 0;
}

int dfs(int x, int y){
    if(x < 0 || y < 0 || x >= SIZE || y >= SIZE) {
        return 0;
    }

    if(GP[x][y] == 1) {
        GP[x][y] = 0;
        SUM++;

        // 4 ¹æÇâ Å½»ö
        for(int i = 0; i < 4; i++) {
            dfs(x + XDIR[i], y + YDIR[i]);
        }

        return 1;
    }

    return 0;
}


int main(){

    int n, sum = 0, temp;
    int q[313] = {0, };

    scanf(" %d", &n);

    // ÀÔ·Â 
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) {
            scanf("%1d", &temp);
            GP[i][j] = temp;
        }
    }

    // Å½»ö
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            SUM = 0;

            if (dfs(i, j) == 1) {
                CNT++;
                q[CNT] = SUM;
            }

        }
    }
    
    //Ãâ·Â
    qsort(q, CNT+1, sizeof(int), compare);
    q[0] = CNT;
    for (int i = 0; i <= CNT; i++) {
        printf("%d\n", q[i]);
    }
    

    return 0;
}

