#include <iostream>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int n;
    long long int rnum = -1, cnt = 0;
    
    cin >> n;
    // 줄어드는 수의 개수를 세어 n과 같아지면 멈춤
    while (n != cnt) {
        rnum++;
        // 줄어드는 수의 가장 큰 값은 9876543210이므로
        // 그 후에도 cnt와 n이 다르면 구할 수 없다는 뜻임
        if (rnum > 9876543210) {
            cout << "-1" << "\n";
            return 0;
        }

        long long int tmp = rnum;
        int div = 0;
        while (1)
        {
            // 모든 자릿수를 비교했을 때 문제가 없었다면 줄어드는 수임
            if (tmp == 0) {
                cnt++;
                break;
            }
            // 일의 자리와 십의 자리를 비교, tmp가 0이 될 때까지 반복
            if (tmp % 10 < tmp / 10 % 10 || tmp < 10) {
                div++;
                tmp /= 10;
            }
            // 줄어드는 수가 아닐 경우 십의 자리를 일의자리로 내린 뒤 1 증가시키고
            // rnum과 같은 자릿수로 만들어줌.
            else {
                tmp /= 10;
                div++;
                tmp++;
                for (int i = 0; i < div; i++)
                    tmp = tmp * 10;
                rnum = tmp - 1;
                break;
            }
        }
    }
    cout << rnum << "\n";

    return 0;
}