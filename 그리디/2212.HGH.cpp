#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    int sum = 0;
    vector<int> v, dist;

    // 입력
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }

    // 좌표간의 거리를 확인하기 위해 정렬
    sort(v.begin(), v.end());

    // 좌표간의 거리를 파악
    for (int i = 0; i < v.size() - 1; i++)
    {
        dist.push_back(v[i + 1] - v[i]);
    }

    /*
       집중국이 k개면, k - 1개의 집중국 사이의 거리가 만들어짐
       수신 가능 영역의 길이의 합을 최소화하기 위해서는 집중국을
       센서 간의 거리가 짧은 곳에 배치해야 함
    */
    // 센서 간의 거리를 정렬
    sort(dist.begin(), dist.end());

    // 거리가 긴 k - 1개를 제외하고 합을 구함
    for (int i = 0; i < n - k; i++)
    {
        sum += dist[i];
    }
    cout << sum << "\n";

    return 0;
}