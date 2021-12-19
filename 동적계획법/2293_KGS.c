// O(n^2) / O(1)

#include <stdio.h>

int DP[10001] = {1, };

int main(){
    int n, k;
    int coins[100];

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++)
        scanf("%d", &coins[i]);

    for (int i = 0; i < n; i++)
        for (int j = coins[i]; j <= k; j++)
            if (j - coins[i] >= 0)
            {
                DP[j] += DP[j - coins[i]];
            }
    
    printf("%d\n", DP[k]);

    return 0;
}