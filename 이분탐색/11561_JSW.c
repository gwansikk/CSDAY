#include <stdio.h>

int main() {
	int t = 0;

	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		unsigned long long n = 0, left = 0, right = 0, mid = 0;

		scanf("%llu", &n);
		left = 1;
		right = n;
		do {
			mid = (left + right) / 2;
			if (mid * (mid + 1) / 2 <= n)
				left = mid;
			else
				right = mid;
		} while (left + 1 < right);
		printf("%llu\n", (left + right) / 2);
	}

	return 0;
}