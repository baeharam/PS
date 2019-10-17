#include <cstdio>
#include <queue>
using namespace std;

int g[51][51], visit[51][51], w, h, sx, sy, ans;
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 }, dy[8] = { -1,0,1,-1,1,-1,0,1 };
queue<pair<int, int> > q;

void bfs()
{
	while (!q.empty()) {
		pair<int, int> s = q.front(); q.pop();
		sx = s.first, sy = s.second;
		for (int i = 0; i < 8; i++) {
			if (sx + dx[i]<0 || sx + dx[i]>h || sy + dy[i]<0 || sy + dy[i]>w) continue;
			if (!visit[sx+dx[i]][sy+dy[i]] && g[sx + dx[i]][sy + dy[i]] == 1) {
				visit[sx + dx[i]][sy + dy[i]] = 1;
				q.push(make_pair(sx + dx[i], sy + dy[i]));
			}
		}
	}
	ans++;
}


int main(void)
{
	while (true) {
		scanf("%d %d", &w, &h); if (!(w&&h)) break;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) scanf("%d", &g[i][j]);
		}
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (!visit[i][j] && g[i][j] == 1) {
					visit[i][j] = 1;
					q.push(make_pair(i, j));
					bfs();
				}
			}
		}
		printf("%d\n", ans);
		ans = 0;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++)
				visit[i][j] = 0;
		}
	}
	return 0;
}