#include <iostream>
#include <queue>

using namespace std;

int tomato[1001][1001];
int n, m, result;
int dx[4] = { 1, 0, -1 , 0 };
int dy[4] = { 0, 1,  0 ,-1 };

queue<pair<int,int>> q;

bool IsInBox(int ny, int nx) {
    return (0 <= nx && 0 <= ny && nx < m && ny < n);
}

void bfs(void) {
    while (!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
 
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
 
            if (IsInBox(ny,nx) == 1 && tomato[ny][nx] == 0) {
                tomato[ny][nx] = tomato[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }
}

int main() {
    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tomato[i][j];
            if (tomato[i][j] == 1) {
                q.push({i, j});
            }
        }
    }

    bfs();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tomato[i][j] == 0) { 
                cout << "-1\n" << '\n';
                return 0;
            }
            if (result < tomato[i][j]) {
                result = tomato[i][j];
            }
        }
    }
    cout << result - 1 << '\n';
    return 0;
}