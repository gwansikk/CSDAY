#include <stdio.h>

int main(void) {
	int t;

	scanf("%d", &t);

	while (t--) {
        unsigned long long left = 0, right, n;
        
		scanf("%lld", &n);
		
		right = n;

		while (left <= right) {
			unsigned long long mid = (left + right) / 2;
			unsigned long long sum = (mid * (mid + 1)) / 2; // 1부터 mid 등차수열의 합

			if (sum == n) {
				right = mid;
				break;
			}

			if (sum < n)
				left = mid + 1;
			else 
				right = mid - 1;
		}

		printf("%lld\n", right);
	}

	return 0;
}
