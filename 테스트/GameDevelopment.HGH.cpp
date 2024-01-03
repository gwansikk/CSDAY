#include <iostream>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt", "rt", stdin);

    int n, m, x, y, d, cnt(0);
    int map[50][50];
    int dx[] = {0, -1, 0, 1}; // 북서남동
    int dy[] = {-1, 0, 1, 0};

    // 입력
    cin >> n >> m;
    cin >> y >> x >> d;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }
    map[y][x] = 2;

    while (1)
    {
        bool flag = false;
        // 현재 방향을 기준으로 왼쪽 방향부터 차례대로 갈 곳을 정함
        for (int i = 0; i < 4; i++)
        {
            d++;
            if (d == 4)
                d = 0;
            // 다음 위치
            int nx = x + dx[d];
            int ny = y + dy[d];
            // 육지 또는 가보지 않은 칸이라면
            if (!map[ny][nx])
            {
                flag = true;
                cnt++;
                map[ny][nx] = 2;
                x = nx;
                y = ny;
                break;
            }
        }
        // 네 방향 모두 이미 가본 칸이거나 바다로 되어 있는 칸이라면
        if (!flag)
        {
            int nd = d + 2;
            if (nd >= 4)
                nd -= 4;

            int nx = x + dx[nd];
            int ny = y + dy[nd];
            // 바다
            if (map[ny][nx] == 1)
                break;
            // 이미 가본 칸
            else
            {
                cnt++;
                map[ny][nx] = 2;
                x = nx;
                y = ny;
            }
        }
    }
    cout << cnt << "\n";

    return 0;
}