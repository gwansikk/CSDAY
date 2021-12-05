#include <stdio.h>

int main() {
	int n = 0, m = 0;
	long long count = 0, left = 1, right = 0, mid = 0, mintime = 0;
	long long t[100001] = { 0 };

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &t[i]);
		if (right < t[i] * m)
			right = t[i] * m;
	}
	while (left <= right) {
		count = 0;
		mid = (left + right) / 2;
		for (int i = 0; i < n; i++)
			count += mid / t[i];
		if (count < m)
			left = mid + 1;
		else {
			mintime = mid;
			right = mid - 1;
		}
	}
	printf("%lld", mintime);

	return 0;
}