#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    long long int maxVal = 0;
    long long int* k;
    
    cin >> n >> m;
    k = new long long int[n];
    for (int i = 0; i < n; i++) {
        cin >> k[i];
        maxVal = max(maxVal, k[i]);
    }

    long long int left = 1, right = m * maxVal;
    long long int res = 0;

    while (left <= right) {
        long long int mid = (left + right) / 2;
        long long int pass = 0;

        for (int i = 0; i < n; i++) {
            pass += mid / k[i];
        }

        if (pass < m) left = mid + 1;
        else {
            res = mid;
            right = mid - 1;
        }
    }
    cout << res << "\n";

    delete(k);

    return 0;
}