// n^2

#include <stdio.h>
#include <math.h>

void hanoi(int N, int one, int two, int three ){
    if(N == 1)
        printf("%d %d\n", one, three);
    else{
        hanoi(N-1, one, three, two);
        printf("%d %d\n", one, three);
        hanoi(N-1, two, one, three);
    }
}

int main() {
    int num = 0; // 원판의 갯수
    int result = 0; // 총 이동 횟수 = 정답
    int first = 1; // 하노이의 첫번째 기둥
    int second = 2; // 하노이의 두번째 기둥
    int third = 3; // 하노이의 세번째 기둥
    
    scanf("%d", &num);
    result = pow(2, num) - 1;
    printf("%d\n", result);

    hanoi(num, first, second, third);
    
    return 0;
}
