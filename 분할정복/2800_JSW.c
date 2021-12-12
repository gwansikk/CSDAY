#include <stdio.h>
#include <string.h>

int main() {
    int j = 0, k = 0;
    char math[201] = {0};
    char mathsplit[20][201] = {0};
    
    scanf("%s", math);
    for(int i = 0; i < strlen(math); i++) {
        if(math[i] == ')' || math[i] == '(') {
            j++;
            k = 0;
            continue;
        }
        mathsplit[j][k] = math[i];
        k++;
    }
    //for(int i = 0; i < j + 1; i++)
    //    printf("%s\n", mathsplit[i]);
    
    return 0;
}
