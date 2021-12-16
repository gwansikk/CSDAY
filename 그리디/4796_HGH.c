// 시간복잡도: n, 공간복잡도: 1

#include <stdio.h>

int main()
{
    int l, p, v;
    int i = 1;

    while (1) {
        int res = 0;

        scanf("%d %d %d", &l, &p, &v);
        if (!(l && p && v)) break;

        res += (v / p) * l;
        v %= p;
        res += (v > l) ? l : v;

        printf("Case %d: %d\n", i++, res);
    }

    return 0;
}