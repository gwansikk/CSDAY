// O(n) ?? / O(1)

#include <stdio.h>
 
int DP[41] = {0, 1, };

int fibo(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;

    // 메모이제이션
    if (DP[n] != 0)
        return DP[n];
    else 
        return DP[n] = fibo(n-1) + fibo(n-2);
}

int main(){
    int i;
    fibo(40); // 미리계산

    scanf("%d", &i);

    // i 만큼 반복
    while (i--){
        int a;

        scanf("%d", &a);
        
        if (a == 0)
            printf("1 0\n");
        else
            printf("%d %d\n", DP[a-1], DP[a]);
    }

    return 0;
}