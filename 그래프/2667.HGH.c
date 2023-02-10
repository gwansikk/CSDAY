#include <stdio.h>
#include <stdlib.h>

int map[26][26];
int houseNum[625];
char dx[] = { 0, 1, 0, -1 };
char dy[] = { 1, 0, -1, 0 };
int n, cnt;

int compare(const void *a, const void *b)
{
    int num1 = *(int*)a;
    int num2 = *(int*)b;

    if (num1 < num2) return -1;
    else if (num1 > num2) return 1;
    else return 0;
}

void DFS(int x, int y)
{   
    int xx, yy;

    for (int i = 0; i < 4; i++) {
        xx = x + dx[i];
        yy = y + dy[i];

        if (xx < 1 || xx > n || yy < 1 || yy > n)
            continue;
        
        if (map[xx][yy] == 1) {
            map[xx][yy] = 0;
            houseNum[cnt]++;
            DFS(xx, yy);
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (map[i][j] == 1) {
                map[i][j] = 0;
                DFS(i, j);
                houseNum[cnt]++;
                cnt++;
            }
        }
    }
    
    qsort(houseNum, cnt, sizeof(int), compare);

    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++) {
        printf("%d\n", houseNum[i]);
    }

    return 0;
}