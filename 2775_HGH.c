#include <stdio.h>

int main() {
	int apt[15][14], sum;
	int t, k, n;
	int f, r; // f는 층, r은 호수

	for (r = 0; r < 14; r++)
		apt[0][r] = r + 1;

	for (f = 1; f < 15; f++) {
		for (int r = 0; r < 14; r++) {
			sum = 0;

			for (int i = 0; i <= r; i++) {
				sum += apt[f - 1][i];
			}

			apt[f][r] = sum;
		}
	}
	
	scanf("%d", &t);

	while (t--) {
		scanf("%d", &k);
		scanf("%d", &n);

		printf("%d\n", apt[k][n - 1]);
	}
	
	return 0;
}