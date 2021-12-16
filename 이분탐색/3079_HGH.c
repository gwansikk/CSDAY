// 시간복잡도: logn, 공간복잡도: 1

#include <stdio.h>
#include <malloc.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main()
{
    int n, m;
    long long int max = 0;
    long long int* k;
    
    scanf("%d %d", &n, &m);
    k = (long long int*)malloc(n * sizeof(long long int));
    for (int i = 0; i < n; i++) {
        scanf("%lld", &k[i]);
        max = MAX(max, k[i]);
    }

    long long int left = 1, right = m * max;
    long long int res = 0;

    while (left <= right) {
        long long int mid = (left + right) / 2;
        long long int pass = 0;

        for (int i = 0; i < n; i++) {
            pass += mid / k[i];
        }

        if (pass < m) left = mid + 1;
        else {
            res = mid;
            right = mid - 1;
        }
    }
    printf("%lld", res);

    free(k);

    return 0;
}