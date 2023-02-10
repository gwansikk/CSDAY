#include <stdio.h>

int main() {
    int l = 0, n = 0, flag = 0, count = 0, buffer = 0, index = 0;
    int s[50] = { 0 };

    scanf("%d", &l);
    for (int i = 1; i <= l; i++)
        scanf("%d ", &s[i]);
    scanf("%d", &n);

    do {
        flag = 0;
        for (int i = 1; i < l; i++)
            if (s[i] > s[i + 1]) {
                flag++;
                buffer = s[i];
                s[i] = s[i + 1];
                s[i + 1] = buffer;
            }
    } while (flag != 0);

    for (int i = 0; i <= l - 1; i++)
        if (n > s[i] && n < s[i + 1]) {
            index = i;
            break;
        }
        else if (i == l - 1) {
            printf("0");
            return 0;
        }

    for (int i = s[index] + 1; i <= n; i++)
        for (int j = i + 1; j < s[index + 1]; j++)
            if (j >= n)
                count++;
    printf("%d", count);

    return 0;
}
