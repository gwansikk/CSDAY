// 미완

#include <iostream>

#define NORTH 0   // 북
#define EAST 1    // 동
#define SOUTH 2   // 남
#define WEST 3    // 서
#define SEA 1     // 바다
#define VISITED 2 // 지나간 길

// using namespace std;

typedef struct _character
{
    int x;
    int y;
    int direction;
} Character;

int n, m;
int move;
Character ch;
int map[52][52];

// 맵 초기화
void init();
// 이동할 다음 위치 계산
Character get_direction(Character c);
// 뒷칸 위치 계산
Character get_back(Character c);
void DFS(int y, int x);

int main()
{
    std::ios_base ::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    freopen("input.txt", "rt", stdin);

    // 맵 1로 초기화 (벽 생성)
    init();

    // 입력
    std::cin >> n >> m;
    std::cin >> ch.y >> ch.x >> ch.direction;
    for (int i = 0; i < m; i++)
    {
        int tmp;
        for (int j = 0; j < n; j++)
        {
            std::cin >> tmp;
            map[i][j] = tmp;
        }
    }

    DFS(ch.y, ch.x);
    std::cout << move << "\n";

    return 0;
}

// 맵 초기화
void init()
{
    for (int i = 0; i < 52; i++)
    {
        for (int j = 0; j < 52; j++)
        {
            map[i][j] = SEA;
        }
    }
}

// 이동할 다음 위치 계산
Character get_direction(Character c)
{
    Character t;

    switch (c.direction)
    {
    case NORTH:
        t.direction = EAST;
        t.y = c.y;
        t.x = c.x - 1;
        break;
    case EAST:
        t.direction = NORTH;
        t.y = c.y - 1;
        t.x = c.x;
        break;
    case SOUTH:
        t.direction = EAST;
        t.y = c.y;
        t.x = c.x + 1;
        break;
    case WEST:
        t.direction = SOUTH;
        t.y = c.y + 1;
        t.x = c.x;
        break;
    }

    return t;
}

Character get_back(Character c)
{
    Character t;

    switch (c.direction)
    {
    case NORTH:
        t.y += 1;
        break;
    case EAST:
        t.x -= 1;
        break;
    case SOUTH:
        t.y -= 1;
        break;
    case WEST:
        t.x += 1;
        break;
    }

    return t;
}

void DFS(int y, int x)
{
    bool flag = false;

    // 맵 출력
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << map[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // 탈출 조건
    if (map[y - 1][x] && map[y + 1][x] && map[y][x - 1] && map[y][x + 1])
        return;

    std::cout << "1" << std::endl;

    // 4방향 탐색
    for (int i = 0; i < 4; i++)
    {
        // 다음 위치 가져옴
        Character next = get_direction(ch);
        std::cout << "2" << std::endl;
        std::cout << next.x << " " << next.y << " " << next.direction << std::endl;

        // 이동 가능한 위치일 경우
        if (!map[next.y][next.x])
        {
            // 지나간 길임을 표시
            flag = true;
            move++;
            map[next.y][next.x] = VISITED;
            ch = next;
            std::cout << "3" << std::endl;
            DFS(ch.y, ch.x);
            std::cout << "4" << std::endl;
            return;
        }
        else
        {
            // 이동 불가능할 경우 왼쪽으로 방향 전환
            ch.direction = next.direction;
        }

        // 네 방향 모두 가본 칸 또는 바다인 경우
        if (!flag)
        {
            ch = get_back(ch);
            // 뒷칸이 바다
            if (map[ch.y][ch.x] == SEA)
            {
                return;
            }
            // 뒷칸이 가본 칸
            else if (map[ch.y][ch.x] == VISITED)
            {
                move++;
                DFS(ch.y, ch.x);
            }
        }
    }
}