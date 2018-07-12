#include <cstdio>

int r, c, max, dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
char board[20][20];
bool visit[26];

void dfs(int x, int y, int move)
{
	visit[board[x][y] - 'A'] = true;
	move++;
	if (move > max) max = move;

	for (int i = 0; i < 4; i++) {
		if (x + dx[i] < 0 || x + dx[i] >= r || y + dy[i] < 0 || y + dy[i] >= c) continue;
		if (visit[board[x + dx[i]][y + dy[i]] - 'A']) continue;
		dfs(x + dx[i], y + dy[i], move);
	}

	visit[board[x][y] - 'A'] = false;
	return;
}

int main()
{
	scanf("%d%d", &r, &c);
	for (int i = 0; i < r; i++) {
		scanf("%s", board[i]);
	}
	dfs(0, 0, 0);
	printf("%d", max);


	return 0;
}