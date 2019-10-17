#include <cstdio>
#include <queue>

int com[101][101];
bool visited[101];
std::queue<int> q;
int n, k, c1, c2, v, num;

void bfs()
{
	q.push(1); visited[1] = true;
	while (!q.empty()) {
		v = q.front(); q.pop();
		for (int i = 1; i <= n; i++) {
			if (com[v][i] == 1 && !visited[i]) {
				q.push(i);
				visited[i] = true;
				num++;
			}
		}
	}
}

int main(void)
{
	scanf("%d%d", &n, &k);
	while (k--) {
		scanf("%d%d", &c1, &c2);
		com[c1][c2] = com[c2][c1] = 1;
	}
	bfs();
	printf("%d", num);
	return 0;
}