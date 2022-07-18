#include <iostream>

using namespace std;

int get_LCS(string a, string b) {
    a = '0' + a;
    b = '0' + b;

    int x(a.length());
    int y(b.length());

    int LCS[x + 1][y + 1] = {0};

    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            if(i == 0 || j == 0) {
                LCS[i][j] = 0;
                continue;
            }
            if(a[i] == b[j])
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            else {
                if(LCS[i - 1][j] > LCS[i][j - 1])
                    LCS[i][j] = LCS[i - 1][j];
                else
                    LCS[i][j] = LCS[i][j - 1];
            }
        }
    }

    return LCS[x - 1][y - 1];
}

int main() {
    string a, b;
    cin >> a >> b;
    int res(0);

    res = get_LCS(a, b);

    cout << res << endl;
    return 0;
}
