#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char s1[1001];
    char s2[1001];
    int dp[1001][1001] = {0};
    int i, j;

    cin >> s1 >> s2;
    for (i = 1; s1[i - 1] != NULL; i++)
    {
        for (j = 1; s2[j - 1] != NULL; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[i - 1][j - 1] << "\n";

    return 0;
}