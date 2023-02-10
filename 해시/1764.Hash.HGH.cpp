#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<string, int> map;
    vector<string> vec;
    int n, m;
    int cnt = 0;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        map.insert({s, i});
    }

    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if (map.find(s) != map.end()) {
            vec.push_back(s);
            cnt++;
        }
    }
    sort(vec.begin(), vec.end());

    cout << cnt << "\n";
    for (string s : vec)
        cout << s << "\n";

    return 0;
}