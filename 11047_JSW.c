#include <stdio.h>

int greedy(int* coin, int n, int k) {
    int count = 0;

    for (int i = n - 1; i >= 0; i--)
        while (coin[i] <= k) {
            k -= coin[i];
            count++;
        }
    if (k > 0)
        count++;

    return count;
}

int main() {
    int n = 0, k = 0;
    int coin[10] = { 0 };

    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &coin[i]);
    printf("%d", greedy(coin, n, k));

    return 0;
}