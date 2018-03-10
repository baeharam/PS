#include <cstdio>

char fractal[2187][2187];

void star(int n, int x, int y)
{	
	if (n == 1) fractal[x][y] = '*';
	else {
		star(n / 3, x, y); star(n / 3, x, y + n / 3); star(n / 3, x, y + n / 3 * 2);
		star(n / 3, x + n / 3, y); star(n / 3, x + n / 3, y + n / 3 * 2);
		star(n / 3, x + n / 3 * 2, y); star(n / 3, x + n / 3 * 2, y + n / 3); star(n / 3, x + n / 3 * 2, y + n / 3 * 2);
	}
}

int main(void)
{
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) fractal[i][j] = ' ';
	}

	star(n,0,0);
	for (int i = 0; i < n; i++) {	
		for (int j = 0; j < n; j++) printf("%c", fractal[i][j]);
		printf("\n");
	}
	return 0;
}