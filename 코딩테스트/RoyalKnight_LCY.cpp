#include <iostream>
using namespace std;

// value의 값이 1 ~ 8인지 확인, 나이트가 정원 안에 존재하는지.
int is_in_garden(int value) {
    if(value > 0 && value < 9)
        return 1;

    return 0;
}

int main() {
    string knight;
    cin >> knight;

    // 가로, 세로 값을 1 ~ 8의 값으로 변형
    int row(knight[0] - 96), col(knight[1] - 48);
    int cnt(0);

    for(int i = 1; i < 3; i++) {
        if(is_in_garden(row + i) && is_in_garden(col + (3 - i)))
            cnt++;
        if(is_in_garden(row + i) && is_in_garden(col - (3 - i)))
            cnt++;
        if(is_in_garden(row - i) && is_in_garden(col + (3 - i)))
            cnt++;
        if(is_in_garden(row - i) && is_in_garden(col - (3 - i)))
            cnt++;
    }
    
    cout << cnt << endl;
    return 0;
}