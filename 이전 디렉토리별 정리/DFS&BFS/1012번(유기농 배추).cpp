#include <cstdio>
using namespace std;

int c[50][50];
bool visited[50][50];
int tc, n, m, k, x, y, ji;

void dfs(int x, int y)
{
	if (x - 1 >= 0 && !visited[x - 1][y] && c[x - 1][y] == 1) {
		visited[x - 1][y] = true;
		dfs(x - 1, y);
	}
	if (x + 1 <= n-1 && !visited[x + 1][y] && c[x + 1][y] == 1) {
		visited[x + 1][y] = true;
		dfs(x + 1, y);
	}
	if (y - 1 >= 0 && !visited[x][y - 1] && c[x][y - 1] == 1) {
		visited[x][y - 1] = true;
		dfs(x, y - 1);
	}
	if (y + 1 <= m-1 && !visited[x][y + 1] && c[x][y + 1] == 1) {
		visited[x][y + 1] = true;
		dfs(x, y + 1);
	}
}

void init()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			c[i][j] = 0;
			visited[i][j] = false;
		}
	}
	ji = 0;
}

int main(void)
{
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d%d", &m, &n, &k);
		while (k--) {
			scanf("%d%d", &x, &y);
			c[y][x] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (c[i][j] == 1 && !visited[i][j]) {
					ji++;
					visited[i][j] = true;
					dfs(i, j);
				}
			}
		}
		printf("%d\n", ji);
		init();
	}
	
	return 0;
}