// O(n)

#include <stdio.h>
#include<string.h>

int stack[100001] = {0,};
int arr_size = 0;

void push(int number){
    stack[arr_size] = number;
    arr_size += 1;
}

void pop(){
    if(arr_size == 0)
        printf("-1\n");
    else{
        printf("%d\n", stack[arr_size]);
        stack[arr_size] = 0;
        arr_size -= 1;
    }
}

void size(){
    printf("%d\n", arr_size);
}

void empty(){
    if(arr_size == 0)
        printf("1\n");
    else
        printf("0\n");
}

void top(){
    printf("%d", stack[arr_size]);
}

int main() {
    int num = 0;
    int input_num = 0;
    char input[10] = {0,};
    
    scanf("%d", &num);
    
    while(num--){
        scanf("%s", input);
        if(!strcmp(input,"push")){
            scanf("%d", &input_num);
            push(input_num);
        }
        else if(!strcmp(input,"pop")){
            pop();
        }
        else if(!strcmp(input,"size")){
            size();
        }
        else if(!strcmp(input,"empty")){
            empty();
        }
        else if(!strcmp(input,"top")){
            top();
        }
            
            
    }
    
    return 0;
}
