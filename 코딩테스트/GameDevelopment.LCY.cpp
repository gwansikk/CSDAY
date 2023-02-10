#include <iostream>
using namespace std;

int N, M, map[51][51];

class Character 
{
public :
    Character(int A, int B, int dir) 
        : PosA(A), PosB(B), dir(dir) { };
    
    void GameStart() {
        res = 0;
        cnt = 0;

        while(cnt < 5) {
            // 앞 칸으로 이동 가능하면 이동, 아니면 방향 전환
            if(IsMovable()) {
                cnt = 0;
                Move();
            } else {
                ChangeDirection();
                cnt++; 
            }

            // cnt가 4가 될 때 (4방향이 모두 움직일 수 없는 방향일 때)
            if(cnt == 4) {
                map[PosA][PosB] = 9;
                // 뒷 면이 바다라면 반복문을 종료시킴, 아니면 뒤로 한 칸 이동
                if(IsSeaBack()) {
                    cnt = 9999; 
                } else {
                    cnt = 0;
                    MoveBack();
                    continue;
                } 
            }
            // 디버깅 용 출력 함수
            // PrintMap();
        }

        // 모든 맵에서 방문 한 칸을 확인
        for(int i = 0 ; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(map[i][j] == 9)
                    res++;
            } 
        }

        // 결과 출력
        cout << res << "\n";
    }

private :
    // 앞 칸이 이동할 수 있는 칸인지 판별
    bool IsMovable() { 
        switch (dir) {
            case 0:
                if(map[PosA - 1][PosB] == 0) return true;
                break;
            case 3:
                if(map[PosA][PosB - 1] == 0) return true;
                break;
            case 2:
                if(map[PosA + 1][PosB] == 0) return true;
                break;
            case 1:
                if(map[PosA][PosB + 1] == 0) return true;
                break;
        }
        return false;
    }

    // 이동 
    void Move() {
        // 9는 현재 칸을 이미 지나간 칸임을 의미
        map[PosA][PosB] = 9; 
        switch (dir) {
            case 0:
                PosA -= 1;
                break;
            case 3: 
                PosB -= 1;
                break;
            case 2:
                PosA += 1;
                break;
            case 1:
                PosB += 1;
                break;
        }
    }

    // 방향 전환
    void ChangeDirection() {
        dir--;
        if(dir == -1) dir = 3;
    }

    // 뒷 칸이 바다인지 판별
    bool IsSeaBack() {
        switch (dir) {
            case 0:
                if(map[PosA + 1][PosB] == 1) return true;
                break;
            case 3:
                if(map[PosA][PosB + 1] == 1) return true;
                break;
            case 2:
                if(map[PosA - 1][PosB] == 1) return true;
                break;
            case 1:
                if(map[PosA][PosB - 1] == 1) return true;
                break;
        }
        return false;
    }

    // 뒤로 이동
    void MoveBack() {
        switch (dir) {
            case 0:
                PosA += 1;
                break;
            case 3: 
                PosB += 1;
                break;
            case 2:
                PosA -= 1;
                break;
            case 1:
                PosB -= 1;
                break;
        }
    }

    // 맵 출력 (테스트용)
    void PrintMap() {
        cout << "\n";
        for(int i = 0 ; i < N; i++) {
            for(int j = 0; j < M; j++) {
                cout << map[i][j] << " ";
            } cout << "\n";
        }
        cout << "PosA : " << PosA
        << "\nPosB : " << PosB 
        << "\ndir : " << dir
        << "\ncnt : " << cnt
        << "\n";
    }

    int PosA, PosB, dir, cnt, res;  
    // 캐릭터가 바라보는 방향, dir
    // 0 : 북쪽     1 : 동쪽
    // 2 : 남쪽     3 : 서쪽
};

int main() {
    int a, b, dir;
    cin >> N >> M >> a >> b >> dir;

    for(int i = 0; i < N; i++) {
        for(int j = 0 ; j < M; j++) {
            cin >> map[i][j];
        }
    }
    
    Character chan(a, b, dir);
    chan.GameStart();

    return 0;
}

