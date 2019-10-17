#include <cstdio>

int g[105][105];

int main(void)
{
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &g[i][j]);
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				g[i][j] = g[i][j] || (g[i][k] && g[k][j]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) printf("%d ", g[i][j]);
		printf("\n");
	}

	return 0;
}