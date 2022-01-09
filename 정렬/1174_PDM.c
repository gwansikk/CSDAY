#include <stdlib.h>
#include <stdio.h>
 
int main(){
    int input = 0; // 입력값
    int num = 0; // 줄어드는 수 생성용
    int cnt = 9; // 배열에 차곡 차곡 쌓기
    int digit10 = 0; // 10의 자리 숫자
    
    long long list[1024] = {0,0,1,2,3,4,5,6,7,8,9};
    
    scanf("%d", &input);
    
    for(int i = 1; i < 10; i++){ // 맨 앞자리에 1~9까지 넣어보는 역할
        num = i * 10;
        cnt++;
        list[cnt] = num;
        while(1){ // 10을 곱하면서 범위까지 늘리는 역할
            if(num > 1000000000){
                break;
            }
            for(int j = 1; j < 10; j++){ // 1의 자리에 0~9까지 넣어보는 역할
                num++;
                digit10 = num % 100 / 10;
                if(digit10 <= j){
                    num--;
                    break;
                }
                else{
                    cnt++;
                    list[cnt] = num;
                }
            }
            num = num * 10;
        }
    }
    
    for(int i = 1; i < 1024; i++){
        printf("%lld\n", list[i]);
    }
    
}

