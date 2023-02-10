// O(n)

#include <stdio.h>

int main(){
    int n;
    int k, v;

    scanf("%d", &n);

     k = n / 5;
     v = n % 5;

     do {
         // 3 으로 안되면 이전 숫자로
         if (v % 3 != 0) {
             k--;
             v += 5; // 뒤로가기
         } else {// 나머지가 3으로 딱 떨어지면 or 5 처리된 경우
             k += v / 3;
             break;
         }

     } while(k > -1); // 뒤로가기 횟수가 처음 값을 넘길경우 탈출

    printf("%d\n", k);

    return 0;
}