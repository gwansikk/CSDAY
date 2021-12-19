// 시간복잡도: n^3, 공간복잡도: 1

#include <stdio.h>

int main()
{
    int n, m;
    int a[98], res = 0;

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for(int i = 0; i < n - 2; i++) {
        for(int j = i + 1; j < n - 1; j++) {
            for(int k = j + 1; k < n; k++) {
                int t = a[i] + a[j] + a[k];
                if (t <= m && res < t) res = t;
            }
        }
    }
    printf("%d\n", res);

    return 0;
}