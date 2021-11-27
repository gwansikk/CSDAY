#include <stdio.h>

int greedy(int l, int p, int v) {
	int visit = v / p, spare = v % p, max = 0;

	if (spare > l)
		spare = l;
	max = visit * l + spare;

	return max;
}

int main() {
	int caseindex = 0;
	int l = 0, p = 0, v = 0;

	while (1) {
		scanf("%d %d %d", &l, &p, &v);
		if (l == 0 && p == 0 && v == 0)
			break;
		caseindex++;
		printf("Case %d: %d\n", caseindex, greedy(l, p, v));
	}

	return 0;
}