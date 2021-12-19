// O(n^3) / O(1)

#include <stdio.h>

int main(){
    int n, m;
    int card[101];
    int max = -1;
    
    scanf(" %d %d", &n, &m);

    for (int i = 0; i < n; i++)
        scanf(" %d",  &card[i]);
    
    // 탐색
    for (int i = 0; i < n - 2; i++) 
    for (int j = i+1; j < n - 1; j++) 
        for (int l = j+1; l < n; l++) 
        {
            int temp = card[i] + card[j] + card[l];

            if (max < temp && temp <= m)
                max = temp;
        }
    
    printf("%d\n", max);
}