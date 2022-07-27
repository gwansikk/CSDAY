#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base ::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	int mod, cnt(0);

	cin >> n >> k;
	while (n > 1)
	{
		if (n % k)
		{
			mod = n % k;
			cnt += mod;
			n -= mod;
		}
		else
		{
			cnt++;
			n /= k;
		}
	}
	if (n == 0)
		cnt--;

	cout << cnt << "\n";

	return 0;
}