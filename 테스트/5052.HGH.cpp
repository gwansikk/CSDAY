#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;

    cin >> t;
    while (t--)
    {
        int n, prevLen;
        string tmp, prev, cur;
        vector<string> vec;
        bool flag = false;

        // 입력
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            vec.push_back(tmp);
        }

        // 일관성 여부를 쉽게 파악하기 위해 정렬
        sort(vec.begin(), vec.end());

        // 전화번호를 가져옴
        prev = vec[0];
        prevLen = vec[0].length();
        for (int i = 1; i < n; i++)
        {
            // 이전 전화번호가 현재 전화번호의 접두어인지 검사
            cur = vec[i].substr(0, prevLen);
            if (prev.compare(cur) == 0)
            {
                flag = true;
                break;
            }
            prev = vec[i];
            prevLen = prev.length();
        }
        if (flag == true)
            puts("NO");
        else
            puts("YES");
    }

    return 0;
}