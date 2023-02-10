#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// qsort를 위한 compare함수
int compare(const void *a, const void *b)
{
    return strcmp((char *)a, (char *)b);
}

int main() {
    char result[50000][101]; // 확장자 기록 배열
    int outputN[50000] = { 0, }; // 각 확장자별 갯수 기록 배열
    int num = 0; // 입력값
    char string[101]; // 파일명 입력 배열
    char *ptr; // 확장자 분리용
    int cnt = 0; // 확장자의 갯수 카운트
    
    scanf("%d", &num);
    
    // 배열 입력 및 확장자 분리
    for (int i = 0; i < num; i++){
        scanf("%s", string);
        ptr = strtok(string, ".");
        ptr = strtok(NULL, ".");
        strcpy(result[i], ptr);
    }
    
    // 확장자를 알파벳 순서로 정렬
    qsort(result, num, sizeof(result[0]), compare);
    
    
    // 배열속 확장자의 갯수 카운트 및 결과 출력
    for(int i = 0; i < num; i++){
        if(strcmp(result[i],result[i+1]) == 0){
            outputN[cnt]++;
        }
        else if(strcmp(result[i],result[i+1]) != 0){
            printf("%s %d\n", result[i], outputN[cnt] + 1);
            cnt++;
        }
    }
    
    return 0;
}
