#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

string input;
vector<int> op;
vector<pair<int, int>> v;
set<string> res;
bool ch[200];

void DFS(int n)
{
    // 마지막 레벨에 도착하면 문자열을 생성하여 set에 넣음
    if (n == v.size())
    {
        string str = "";
        for (int i = 0; i < input.size(); i++)
        {
            if (ch[i])
                continue;
            str += input[i];
        }
        res.insert(str);
    }
    // 모든 괄호쌍에 대해 포함/포함X 두 갈래로 나눠 트리구조를 만듦
    else
    {
        int x = v[n].first;  // ( 위치
        int y = v[n].second; // ) 위치

        // 괄호쌍을 포함하지 않음
        ch[x] = ch[y] = true;
        DFS(n + 1);
        // 괄호쌍을 포함함
        ch[x] = ch[y] = false;
        DFS(n + 1);
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> input;
    // 괄호의 쌍을 찾아 위치 저장
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == '(')
            op.push_back(i);
        else if (input[i] == ')')
        {
            v.push_back({op.back(), i});
            op.pop_back();
        }
    }

    DFS(0);

    // DFS 알고리즘에서 자기자신도 insert하기 때문에 set에서 지움
    res.erase(input);
    for (string s : res)
        cout << s << "\n";

    return 0;
}