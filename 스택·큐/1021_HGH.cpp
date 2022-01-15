// 시간복잡도: n

#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int n, m;
    int m_data[50];
    int cnt = 0;
    deque<int> dq;

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> m_data[i];
    }

    // 덱 초기화(1 ~ n)
    for (int i = 1; i <= n; i++) {
        dq.push_back(i);
    }

    // 1, 2, 3 연산을 통해 결과를 도출
    for (int i = 0; i < m; i++) {
        int pos;

        if (dq.size() == 1) break;

        // 뽑아낼 원소의 위치 탐색
        for (int j = 0; j < n; j++) {
            if (m_data[i] == dq.at(j)) {
                pos = j;
                break;
            }
        }

        // 뽑아낼 원소가 앞쪽에 있을 경우 2번 연산을 통해 앞쪽으로 이동시킴
        if (pos <= dq.size() / 2) {
            for (int j = 0; j < pos; j++) {
                dq.push_back(dq.front());
                dq.pop_front();
                cnt++;
            }
            dq.pop_front(); // 원소를 뽑음
        }
        // 뽑아낼 원소가 뒤쪽에 있을 경우 3번 연산을 통해 뒤쪽으로 이동
        else {
            for (int j = 0; j < dq.size() - pos; j++) {
                dq.push_front(dq.back());
                dq.pop_back();
                cnt++;
            }
            dq.pop_front(); // 원소를 뽑음
        }
    }
    cout << cnt << "\n";

    return 0;
}