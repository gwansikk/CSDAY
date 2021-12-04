#include <stdio.h>

typedef unsigned long long ull;

int main()
{
    int t;

    scanf("%d", &t);
    while (t--) {
        ull n;
        int res = 0;

        scanf("%llu", &n);

        ull left = 1, right = n;
        while (left <= right) {
            ull mid = (left + right) / 2;

            if (mid * (mid + 1) / 2 > n) {
                right = mid - 1;
            }
            else {
                res = mid;
                left = mid + 1;
            }
        }
        printf("%d\n", res);
    }

    return 0;
}