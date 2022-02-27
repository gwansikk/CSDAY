#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, cnt = 0;
    vector<string> vec;
    vector<string> res;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end());

    for (int i = 0; i < m; i++) {
        string tmp;
        cin >> tmp;
        if (binary_search(vec.begin(), vec.end(), tmp)) {
            cnt++;
            res.push_back(tmp);
        }
    }

    sort(res.begin(), res.end());
    cout << cnt << endl;
    for (string elem : res) {
        cout << elem << endl;
    }

    return 0;
}