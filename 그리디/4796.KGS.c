// O(n) / O(1)

#include <stdio.h>

int main(){
    int l, p, v;
    int cnt = 1;

    while (1) {
        int res = 0;

        scanf("%d %d %d", &l, &p, &v);

        if (l + p + v == 0)
            break;
        
        res += (v / p) * l;
        res += (v % p > l)? l : (v % p);
        printf("Case %d: %d\n", cnt++, res);

    }
    
    return 0;
}