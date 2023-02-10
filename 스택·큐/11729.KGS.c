//O(n)
#include <stdio.h>

int N = 0;

void move(int n, int x, int y, int t){
	
	if (n > 1)
		move(n-1, x, 6-x-y, t);
	
	if (t == 1)
		printf("%d %d\n", x, y);
	else
		N++;

	if (n > 1)
		move(n-1, 6-x-y, y, t);
}

int main() {
	int n;
	
	scanf("%d", &n);
	
	move(n, 1, 3, 0);
	printf("%d\n", N);
	
	move(n, 1, 3, 1);
}