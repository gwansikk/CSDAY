// 수정 예정

#include <stdio.h>
#include <math.h>

int main()
{
    int l, w, h;
    int n, cube[20][2];
    int v, res = 0;

    scanf("%d %d %d", &l, &w, &h);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &cube[i][0], &cube[i][1]);
    }

    v = l * w * h;
    for (int i = n - 1; i >= 0; i--) {
        if (v == 0) break;

        int t = pow(pow(2, cube[i][0]), 3);
        if (t * cube[i][1] <= v) {
            res += cube[i][1];
            v -= t * cube[i][1];
        }
        else {
            int c = v / t;
            res += c;
            v -= t * c;
        }
        printf("i: %d, t: %d, res: %d, v: %d\n", i, t, res, v);
    }

    if (v == 0) printf("%d\n", res);
    else printf("-1\n");

    return 0;
}