#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b)
{
    return strcmp((char *)a, (char *)b);
}

int main() {
    int n, m = 0;
    char neverH[50000][20];
    char neverHS[50000][20];
    char temp[20];
    int cnt = 0;
    
    scanf("%d %d", &n, &m);
    
    for(int i = 0; i < n; i++){ // 듣도 못한 사람이름 입력
        scanf("%s", neverH[i]);
    }
    
    // 빠른 비교를 위한 사전순 정렬
    qsort(neverH, n, sizeof(neverH[0]), compare);
    
    for(int i = 0; i < m; i++){ // 보도못한 사람 이름 입력과 동시에 비교
        scanf("%s", temp);
        for(int j = 0; j < n; j++){
            if(strcmp(temp,neverH[j]) == 0){
                strcpy(neverHS[cnt], neverH[j]);
                cnt++;
                break;
            }
            else if(strcmp(temp,neverH[j]) == -1){
                break;
            }
            
        }
    }

    // 사전순 정렬
    qsort(neverHS, cnt, sizeof(neverHS[0]), compare);

    // 최종 값 출력
    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i++){
        printf("%s\n", neverHS[i]);
    }
    
    return 0;
}
