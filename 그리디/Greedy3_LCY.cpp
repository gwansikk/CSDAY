#include <iostream>
using namespace std;

int large_num(int n, int m, int k, int arr[]) {
    int res(0), cnt(0);
    int max1(arr[0]), max2(max1);

    for(int i = 1; i < n; i++) {
        if(max1 < arr[i]){
            max2 = max1;       
            max1 = arr[i];      
        } else if(max1 == arr[i])
            max2 = max1;
    }
    // cout << max1 << " " << max2 << endl;

    for (int i = 0; i < m; i++) {
        if(cnt != k) {
            res += max1;
            cnt++;
        } else {
            res += max2;
            cnt = 0;
        }
        // cout << res << " " << cnt << endl;
    }

    return res;
}

int main() {
    int n, m, k;

    cin >> n >> m >> k;
    int arr[n] = {0};
    
    for(int i = 0 ; i < n; i ++) {
        cin >> arr[i];
    }
    
    cout << large_num(n, m, k, arr) << endl;
}