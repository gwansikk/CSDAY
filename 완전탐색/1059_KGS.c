// O(n^2) / O(n)

#include <stdio.h>
#include <stdlib.h>

int compare(const void* num1, const void* num2) {
    if(*(int*)num1 > *(int*)num2)
        return 1;
    else if(*(int*)num1 < *(int*)num2)
        return -1;
    else
        return 0;
}

int main(){
    int l, n, cnt = 0;
    int *s;
    int first, end;

    scanf(" %d", &l);
    s = malloc(sizeof(int) * l);


    for (int i = 0; i < l; i++)
        scanf(" %d", &s[i]);

    scanf (" %d", &n);

    // 집합 S 정렬.
    qsort( s, l, sizeof(int), compare);

    // N보다 첫번 째로 큰 값 찾기.
    for (int i = 0; i < l; i++) 
        if (n <= s[i]) {
            first = s[i - 1];
            end = s[i];
            break;
        }

    
    // 구간이 없을 경우.
    if (end == n) {
        printf("0\n");
    } else {
        for (int i = first + 1; i < end; i++)    
        for (int j = i + 1; j < end; j++)
                if (i <= n && n <= j) 
                    cnt++;

        printf("%d\n", cnt);
    }


    free(s);
    return 0;
}