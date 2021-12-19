// 미완.

#include <stdio.h>
#include <math.h>

int BOX;
int CNT;

int cubeinabox(int cube, int num) {

	while (BOX >= cube) {
		if(num > 0) {
			num--;
			BOX -= cube;
			printf("-%d\n", cube);
			CNT++;
		} else {
			break;
		}

	}
	
	return 0;
}

int main(void) {
	int l, w, h, n, temp;
	int cube[20];

	scanf("%d %d %d", &l, &w, &h);
	BOX = l * w * h;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &temp, &cube[i]);
	}

	n = n - 1;
	printf("\nBOX = %d\n", BOX);

	for (int i = n; i >= 0; i--) {
		int temp_cube = pow(pow(2, i), 3);

		if (BOX < 0)
			break;

		printf("i:%d C:%d n:%d B:%d\n", i, temp_cube, cube[i], BOX);
		cubeinabox(temp_cube, cube[i]);
	}
	
	if (BOX == 0)
		printf("%d\n", CNT);
	else
		printf("-1\n");

	return 0;
}
