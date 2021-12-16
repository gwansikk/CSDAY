// 시간복잡도: n, 공간복잡도: 1

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int l, n, cnt = 0;
    vector<int> v;

    cin >> l;
    for (int i = 0; i < l; i++) {
        int t;
        cin >> t;
        v.push_back(t);
    }
    v.push_back(0);
    sort(v.begin(), v.end());

    cin >> n;

    int s, e;
    bool flag = true;

    for (int i = 1; i <= l; i++) {
        if (n == v[i]) {
            flag = false;
            break;
        }
        else if (n < v[i]) {
            s = v[i - 1] + 1;
            e = v[i] - 1;
            break;
        }
    }

    if (flag) cout << (n - s) * (e - n + 1) + (e - n) << "\n";
    else cout << 0 << "\n";

    return 0;
}