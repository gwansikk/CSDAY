// O(n^2)

#include <stdio.h>

int CNT = 0;

int bsort(const int *list, int n) {
    for (int i = n-1; i > 0; i--)
        // 작아지는 수가 아닐 경우 탈출
        if (list[i] == list[i-1]) {
            int temp = 1;

            for (int j = 0; j < i; j++)
                temp *= 10;
            
            return temp;
        } else if(list[i] < list[i-1])
            return -1;

    CNT++;
    return 0;
}

int main() {
    int site[12] = {0, };
    long n, i = 0;

    scanf(" %ld", &n);

    // 제한
    if (n > 1023) {
        printf("-1\n");
        return 0;
    } else if (n == 1023) {
        printf("9876543210\n");
        return 0;
    }

    while (1) {
        int number = i;
        int j = 0;

        // 자리 나눠서 배열에 넣기
        while (number != 0) {
            site[j++] = number % 10;
            number /= 10;
        }

        int temp = bsort(site, j);

        // 건너뛰기
        if (temp >= 10) {
            i /= temp; i += 1;
            i *= temp; i--;
        } else if (CNT == n) {
            printf("%ld\n", i);
            break;
        }

        i++;
    }
    
    return 0;
}