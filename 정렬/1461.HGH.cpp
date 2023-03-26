#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, mIdx = 0, dist = 0;
    int *num;

    // 입력
    cin >> n >> m;
    num = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        if (num[i] < 0)
            mIdx++;
    }

    // 오름차순 정렬
    sort(num, num + n);

    /* 최소 거리를 위해 양수와 음수를 나눠서 계산 */
    // 음수 좌표 최소거리 계산
    for (int i = 0; i < mIdx; i += m)
    {
        dist += num[i] * -2; // 0 ~ 좌표까지 왕복하므로 * 2를 함
    }
    // 양수 좌표 최소거리 계산
    for (int i = n - 1; i >= mIdx; i -= m)
    {
        dist += num[i] * 2;
    }
    // 책을 원위치에 두고 0으로 돌아가지 않아도 됨
    // => 가장 먼 거리를 이동할 때 왕복하지 않아야 최소거리가 나옴
    dist -= max(-num[0], num[n - 1]);

    cout << dist << "\n";

    delete[] num;

    return 0;
}