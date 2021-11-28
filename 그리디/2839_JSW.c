#include <stdio.h>

int greedy(int n) {
    int x = 0, y = 0;

    for (int i = n / 5; i >= 0; i--)
        if ((n - i * 5) % 3 == 0) {
            x = (n - i * 5) / 3;
            y = i;
            break;
        }

    if (x == 0 && y == 0)
        return -1;
    else
        return x + y;
}

int main() {
    int n = 0, count = 0;

    scanf("%d", &n);
    count = greedy(n);
    printf("%d", count);

    return 0;
}