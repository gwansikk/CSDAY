#include <stdio.h>
#include <stdlib.h>

long long num[1024] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
int count = 10;

int static compare(const void* first, const void* second) {
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}

void FindDecreaseNum(long long input) {
    if (input % 10 == 0)
        return;

    for (int i = 0; i < input % 10; i++) {
        long long newinput = 0;

        num[count] = input * 10 + i;
        newinput = num[count];
        count++;

        FindDecreaseNum(newinput);
    }
}

int main() {
    int n = 0;

    for (int i = 0; i < 10; i++)
        FindDecreaseNum(i);
    qsort(num, count, sizeof(long long), compare);

    scanf("%d", &n);
    n > count ? printf("-1") : printf("%lld", num[n - 1]);

    return 0;
}
