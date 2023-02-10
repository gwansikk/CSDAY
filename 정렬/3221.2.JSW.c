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
    int location[70000] = { 0 };
    int l = 0, t = 0, n = 0;

    scanf("%d %d %d", &l, &t, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %c", &location[i], &way);

        if (way == 'D') {
            if (t > l - location[i]) {
                int mid = t - (l - location[i]);
                int q = mid / l;
                int r = mid % l;

                location[i] = (q % 2 == 0) ? l - r : r;
            }
            else
                location[i] += t;
        }
        else {
            if (t > location[i]) {
                int mid = t - location[i];
                int q = mid / l;
                int r = mid % l;

                location[i] = (q % 2 == 0) ? r : l - r;
            }
            else
                location[i] -= t;
        }
    }

    qsort(location, n, sizeof(int), compare);
    for (int i = 0; i < n; i++)
        printf("%d ", location[i]);

    return 0;
}
