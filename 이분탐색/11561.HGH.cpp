#include <iostream>

using namespace std;

typedef unsigned long long ull;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;

    cin >> t;
    while (t--)
    {
        ull n;
        int res = 0;

        cin >> n;

        ull left = 1, right = n;
        while (left <= right)
        {
            ull mid = (left + right) / 2;

            if (mid * (mid + 1) / 2 > n)
            {
                right = mid - 1;
            }
            else
            {
                res = mid;
                left = mid + 1;
            }
        }
        cout << res << "\n";
    }

    return 0;
}