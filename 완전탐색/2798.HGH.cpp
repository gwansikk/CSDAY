#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    int res = 0;
    vector<int> card;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        card.push_back(t);
    }

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                int sum = card[i] + card[j] + card[k];
                if (sum > res && sum <= m) res = sum;
            }
        }
    }
    cout << res << "\n";

    return 0;
}