#include <stdio.h>
#include <stdlib.h>

int compare(void* first, void* second) {
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}

int main() {
    char way = 0;
    int direction[70000] = { 0 };
    int location[70000] = { 0 };
    int l = 0, t = 0, n = 0;

    scanf("%d %d %d", &l, &t, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %c", &location[i], &way);
        if (way == 'D')
            direction[i] = 1;
        else
            direction[i] = -1;
    }

    while (t--) {
        for (int i = 0; i < n; i++) {
            if (location[i] == 0)
                direction[i] = 1;
            else if (location[i] == l)
                direction[i] = -1;
            location[i] += direction[i];
        }
    }

    qsort(location, n, sizeof(int), compare);
    for (int i = 0; i < n; i++)
        printf("%d ", location[i]);

    return 0;
}
