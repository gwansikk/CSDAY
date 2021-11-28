#include <stdio.h>

int dp[41] = {0, 1};

int fibonacci(int n)
{
    if (n <= 0) return 0;
    else if (n == 1) return 1;

    if (dp[n] != 0) return dp[n];
    else return dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int t;

    scanf("%d", &t);
    while (t--) {
        int n;

        scanf("%d", &n);
        if (n == 0) printf("1 0\n");
        else {
            fibonacci(n);
            printf("%d %d\n", dp[n - 1], dp[n]);
        }
    }

    return 0;
}