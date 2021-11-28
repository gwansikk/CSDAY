#include <stdio.h>

int main(){
    int n, k;
    int coin[10], cnt = 0;

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++)
        scanf("%d", &coin[i]);
    
    for (int i = n-1; i >= 0; i--) {
         if (coin[i] <= k) {
            cnt += k / coin[i]; 
            k = k % coin[i];
        }

        if (k == 0)
            break;
    }

    printf("%d\n", cnt);

    return 0;
}