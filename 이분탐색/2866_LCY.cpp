#include <iostream>
#include <set>

using namespace std;

string table[1001];

int main() {
    int R, C;
    bool check = false;

    cin >> R >> C;
    int start = 1, end = R;

    for(int i = 1; i <= R; i++) {
        cin >> table[i];
    }
    
    while (start <= end) {
        int mid = (start + end) / 2;
        set<string> s;

        check = true;
        for (int i = 0; i < C; i++) {
            string tmp = "";
            for (int j = mid; j <= R; j++) {
                tmp += table[j][i];
            }
            if(s.find(tmp) == s.end()) {
                s.insert(tmp);
            }
            else {
                check = false;
                break;
            }
            // cout << i << " : " << tmp << endl;
        }

        if(check) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
        // cout << "start : " << start << "\nend : " << end << "\nmid : " << mid << "\ncheck : " << check << "\n\n" << endl;
    }

    cout << start - 2;
    return 0;
}
