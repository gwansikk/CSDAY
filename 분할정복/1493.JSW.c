#include <stdio.h>
#include <stdlib.h>

int cube[20] = { 0 };

int countcubes(int length, int width, int height) {
    int count = 0, min = 0, maxsize = 0, realsize = 1;
    
    if(length == 0 || width == 0 || height == 0)
        return 0;
    min = length < (width < height ? width : height) ? length : (width < height ? width : height);
    while(min > 1) {
        min /= 2;
        maxsize++;
    }
    for(int i = maxsize; i >= 0; i--) {
        if(cube[i] > 0) {
            maxsize = i;
            count++;
            cube[i]--;
            break;
        }
        if(i == 0) {
            printf("-1");
            exit(0);
        }
    }
    for(int i = maxsize; i > 0; i--)
        realsize *= 2;
    count += countcubes(length - realsize, realsize, realsize) + countcubes(length, realsize, height - realsize) + countcubes(length, width - realsize, height);
    
    return count;
}

int main() {
    int length = 0, width = 0, height = 0, n = 0, cubesize = 0, ans = 0;
    
    scanf("%d %d %d %d", &length, &width, &height, &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &cubesize);
        scanf("%d", &cube[cubesize]);
    }
    ans = countcubes(length, width, height);
    printf("%d", ans);
    
    return 0;
}
