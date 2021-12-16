#include <stdio.h>

int main()
{
    int n, m;
    int a[98], res = 0;

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n - 2; i++) {
        for (int j = 1; j < n - 1; j++) {
            for (int k = 2; k < n; k++) {
                if (i != j && j != k && k != i) {
                    int t = a[i] + a[j] + a[k];
                    if (t <= m && res < t) res = t;
                }
            }
        }
    }
    printf("%d\n", res);

    return 0;
}