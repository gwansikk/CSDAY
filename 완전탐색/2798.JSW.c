#include <stdio.h>

int main() {
    int n = 0, m = 0, ans = 0;
    int card[100] = {0};
    
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%d", &card[i]);
    
    for(int i = 0; i < n - 2; i++)
        for(int j = i + 1; j < n - 1; j++)
            for(int k = j + 1; k < n; k++) {
                int sum = card[i] + card[j] + card[k];
                
                if(sum == m) {
                    printf("%d", sum);
                    return 0;
                }
                else if(m > sum && sum > ans)
                    ans = sum;
            }
    
    printf("%d", ans);
    
    return 0;
}
