#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    int res = 0;

    cin >> n >> k;
    vector<int> dp(k + 1);

    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        int w, v;

        cin >> w >> v;
        for (int j = k; j >= w; j--) {
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }
    cout << dp[k] << "\n";

    return 0;
}