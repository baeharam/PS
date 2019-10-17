#include <cstdio>

int b[35][35], tc, w, e;

int bino(int n, int r)
{
	for (int i = 0; i <= n; i++) b[i][0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			b[i][j] = b[i - 1][j - 1] + b[i - 1][j];
		}
	}
	return b[n][r];
}


int main(void)
{
	scanf("%d",&tc);
	while (tc--) {
		scanf("%d%d", &w, &e);
		printf("%d\n", bino(e, w));
	}
	return 0;
}