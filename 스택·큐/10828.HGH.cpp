// 시간복잡도: n

#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int stk[10000], top = -1, value;
    string str;

    cin >> n;
    while (n--) {
        cin >> str;
        if (str == "push") {
            cin >> value;
            stk[++top] = value;
        }
        else if (str == "pop") {
            if (top < 0) cout << "-1" << "\n";
            else cout << stk[top--] << "\n";
        }
        else if (str == "size") {
            cout << top + 1 << "\n";
        }
        else if (str == "empty") {
            if (top < 0) cout << "1" << "\n";
            else cout << "0" << "\n";
        }
        else if (str == "top") {
            if (top < 0) cout << "-1" << "\n";
            else cout << stk[top] << "\n";
        }
    }

    return 0;
}