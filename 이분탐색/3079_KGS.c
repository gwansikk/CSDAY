#include <stdio.h>
#define MAX(a,b)  (((a) > (b)) ? (a) : (b))
#define MIN(a,b)  (((a) < (b)) ? (a) : (b))

int main(){
    int n, m;
    unsigned long long int max = 0;
    unsigned long long int left = 0, right, mid;
    
    scanf(" %d %d", &n, &m);

    unsigned long long int gate[n];

    for (int i = 0; i < n; i++) {
        scanf(" %lld", &gate[i]);
        max = MAX(max, gate[i]);
    }

    //최대 걸리는 시간
    right = max * m;  

    while (left + 1 < right) {
        mid = (left + right)/2;

        // 시간 내에 처리할 수 있는 인원
        unsigned long long temp = 0;

        for (int i = 0; i < n; i++)
            temp += mid / gate[i]; // 해당 심사대가 정해진 시간내에 몇 명 검사할 수 있는지

        // 시간에 인원을 처리할 수 없으면
        if (temp < m) {
            left = mid;
        } else { // 시간에 인원을 처리할 수 있으면
            right = mid;
        }

    }
    
    printf("%lld\n", right);

    return 0;
}