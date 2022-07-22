#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base ::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k;
	vector<int> vec;

	// 입력
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}
	// 정렬
	sort(vec.begin(), vec.end());

	// 첫 번째, 두 번째 큰 수 구하기
	int f = vec.at(n - 1), s = vec.at(n - 2);
	// k의 배수번 째 더할 때마다 두 번째로 큰 수를 더함
	cout << f * (m - m % k) + s * (m % k) << "\n";

	return 0;
}