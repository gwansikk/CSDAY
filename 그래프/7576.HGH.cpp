#include <iostream>
#include <vector>
#include <queue>

#define RIPE 1   // 익은 토마토
#define UNRIPE 0 // 안 익은 토마토

using namespace std;

typedef struct
{
    int x;
    int y;
} Point;

int map[1000][1000];
int n, m, day;
char dx[] = {0, 1, 0, -1};
char dy[] = {1, 0, -1, 0};
queue<Point> q;

void BFS()
{
    // 상하좌우에 안 익은 토마토가 존재할 때까지 실행
    while (!q.empty())
    {
        Point p = q.front();
        q.pop();

        // 상하좌우에 안 익은 토마토가 있는지 검사
        for (int i = 0; i < 4; i++)
        {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];

            // 배열의 범위를 벗어나는지 검사
            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;

            // 안 익은 경우 익히고
            // 큐에 추가하여 다음 번에 주위를 탐색할 수 있도록 함
            if (map[ny][nx] == UNRIPE)
            {
                map[ny][nx] = map[p.y][p.x] + 1;
                if (map[ny][nx] > day)
                    day = map[ny][nx];
                q.push({nx, ny});
            }
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool flag = false;

    // 입력
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == RIPE)
            {
                q.push({j, i});
            }
        }
    }

    // 상하좌우의 토마토를 익힘
    BFS();

    // BFS 이후 안 익은 토마토가 존재하는지 확인
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == UNRIPE)
                flag = true;
        }
    }

    // 안 익은 토마토가 존재하면 -1 | 존재하지 않으면 최소 날짜 출력
    if (flag)
        cout << -1 << "\n";
    else
        // day가 2부터 시작되므로 day에서 1을 뺌
        // 처음부터 다 익어져 있던 경우 예외처리
        cout << (day == 0 ? 0 : day - 1) << "\n";

    return 0;
}