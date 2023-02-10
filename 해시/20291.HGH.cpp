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

    int n, pos, cnt = 0; 
    string fileName, extName, comp;
    vector<string> ext;

    cin >> n;
    while (n--) {
        cin >> fileName;
        pos = fileName.find('.'); // 파일이름에서 '.'의 위치 탐색
        extName = fileName.substr(pos + 1); // '.' 뒤의 문자(확장자)를 저장함
        ext.push_back(extName); // 확장자명을 저장함
    }
    sort(ext.begin(), ext.end()); // 확장자명 정렬

    // 다른 확장자명이 나올 때까지 개수를 세고 출력함
    comp = ext[0];
    for (string s : ext) {
        if (comp == s) cnt++;
        else {
            cout << comp << " " << cnt << "\n";
            comp = s;
            cnt = 1;
        }
    }
    cout << comp << " " << cnt << "\n";

    return 0;
}