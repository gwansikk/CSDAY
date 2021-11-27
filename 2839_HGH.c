#include <stdio.h>

int main() {
	int n, kg5 = 0, kg3 = 0;

	scanf("%d", &n);

	kg5 = n / 5;

	while (1) {
		if ((n - 5 * kg5) % 3 == 0) {
			kg3 = (n - 5 * kg5) / 3;
			break;
		}
		else
			kg5--;

		if (kg5 == -1) {
			printf("-1\n");
			return 0;
		}
	}
	printf("%d\n", kg5 + kg3);

	return 0;
}