// 미완성

#include <stdio.h>

int dy[10001] = { 0, 1, 2 };

int DFS(int n)
{
    if (n < 0)
        return 0;

    if (dy[n] != 0)
        return dy[n];
    else
        return DFS(n - 1) + DFS(n - 2) + DFS(n - 3);
}

int main()
{
    int t, n;

    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        printf("%d\n", DFS(n));
    }

    return 0;
}