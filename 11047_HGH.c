#include <stdio.h>
#include <malloc.h>

int main()
{
    int n, k;
    int cnt = 0;
    int* coin;

    scanf("%d %d", &n, &k);
    coin = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &coin[i]);
    }

    for (int i = n - 1; i >= 0; i--) {
        if (k == 0) break;
        
        int t = k / coin[i];
        if (t > 0) {
            cnt += t;
            k -= coin[i] * t;
        }
    }
    printf("%d\n", cnt);
    
    free(coin);

    return 0;
}