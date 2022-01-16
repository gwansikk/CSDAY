// O(n^2) 미완
// Deque
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, m, key, cnt = 0;
    int* que;

    scanf(" %d %d", &n, &m);
    
    que = (int*)calloc( n+1, sizeof(int));

    for (int p = 0; p < m; p++) {
        int i, index = -1;
        scanf("%d", &key);

        // 탐색, 찾으면 탈출
        for (i = 0; index != key; ){
            i += (que[index] == 0);
            index = (index % n) + 1;
        }

        cnt += (i < n-p-i)? i : n-p-i;
        que[index] = 1;
    }

    printf("%d\n", cnt);
    
    return 0;
}
