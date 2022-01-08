// 미완성

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, cnt = 0;
long long d = 0;

// qsort 정렬기준(내림차순)
int compare(const void *a, const void *b)
{
    return strcmp((char *)b, (char *)a);
}

// 문자열 내 같은 숫자의 인덱스 탐색
int find(char const *src, int n)
{
    int i = strlen(src) - 1;

    for (;i >= 0; i--) {
        if (src[i] == n) return i;
    }
}

// 줄어드는 수 검증
int detect(char const *src, char const *dst)
{
    if (strcmp((char *)dst, (char *)src) != 0) return -1;
    for (int i = 0; i < strlen(src) - 1; ++i) {
        if (src[i] == src[i + 1]) return find(src, src[i]);
    }

    return 0;
}

// 줄어드는 수 중 마지막 수인지 검증(ex. 9, 98, 987...)
int end(char const *src, int len)
{
    char e = '9';

    if (len == 1) {
        if(src[0] == e) return 1;
        else return 0;
    }

    for (int i = 0; i < len - 1; i++) {
        if (src[i] != e) return 0;
        e--;
    }
    
    // 9876543210이 줄어드는 수의 마지막이므로 예외처리함
    if (e < '0') return 0;
    else return 1;
}

void solve(long long x)
{
    printf("cnt: %d, d: %lld\n", cnt, d);
    char cd[11], copy[11];
    int idx, len;

    /* n번째 수를 찾았을 경우 종료 */
    if (n == cnt) return;

    /* 숫자를 문자열로 변환 */
    ltoa(x, cd, 10);
    strcpy(copy, cd);
    len = strlen(cd);
    
    /* 문자열 정렬 */
    qsort(cd, len, sizeof(char), compare);
    //printf("%s %s\n", cd, copy);

    /* 문자열 정렬 전과 후를 대조 */
    // 줄어드는 수일 경우
    if (!(idx = detect(cd, copy))) {
        cnt++;
        // 마지막 수일 경우 자릿수를 1개 늘림(ex. 9 -> 10)
        if (end(cd, len)) {
            cd[0] = '1';
            for (int i = 1; i <= len; i++) {
                cd[i] = '0';
            }
            cd[len + 1] = '\0';
        }
        // 일의 자리를 1 증가시킴
        else cd[len - 1]++;
        solve((d = atoll(cd)));
    }
    // 줄어드는 수가 아닌 경우 문제되는 자릿수를 0으로 바꾸고 그 앞자리 수를 증가시킴 (ex. 101 -> 110)
    else {
        cd[idx - 1]++;
        cd[idx] = '0';
        solve((d = atoll(cd)));
    }
}

int main()
{
    scanf("%d", &n);
    solve(0);
    printf("%lld\n", d);

    return 0;
}