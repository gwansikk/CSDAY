#include <iostream>

using namespace std;

int DP[201][201] = {0};

int main() {
    int N, K;

    cin >> N >> K;

    for (int i = 0; i <= N; i++) {
        DP[1][i] = 1;
    }

    for (int i = 2; i <= K; i++) {
        for (int j = 0; j <= N; j++) {
            for (int k = 0; k <= j; k++) {
                DP[i][j] += DP[i - 1][k];
            }
        }
    }

    DP[K][N] %= 1000000000;
    cout << DP[K][N];
}