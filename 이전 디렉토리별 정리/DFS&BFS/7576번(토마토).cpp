#include <iostream>
#include <queue>
using namespace std;

struct tc{
	int cond;
	int x;
	int y;
};

tc tomato[1005][1005], t;
queue<tc> q;

int main(void)
{
	// n이 열의 개수, m이 행의 개수이므로 반대로 입력받는다.
	int n, m; cin >> m >> n;

	// 안 익은 토마토 개수
	int tomatoNum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tomato[i][j].cond;
			// x에 행을, y에 열을 저장한다.
			// 상/하/좌/우와 비교하기 위해서!
			tomato[i][j].x = i;
			tomato[i][j].y = j;
			if (tomato[i][j].cond==0) tomatoNum++;
			else if (tomato[i][j].cond == 1) q.push(tomato[i][j]);
		}
	}

	while (!q.empty()) {
		t = q.front(); q.pop();
		// 위쪽
		if (t.x - 1 >= 0 && tomato[t.x-1][t.y].cond == 0) {
			// t.cond+1이 핵심인데 토마토가 익어가는 날짜를 구하기가 어려웠지만 구조체에 cond를 저장해서
			// 다음 토마토로 하여금 거기서 1증가 시킴으로 구할 수 있었다.
			tomato[t.x-1][t.y].cond = t.cond+1;
			q.push(tomato[t.x-1][t.y]);
		}
		// 아래쪽
		if (t.x + 1 <= n-1 && tomato[t.x+1][t.y].cond == 0) {
			tomato[t.x+1][t.y].cond = t.cond+1;
			q.push(tomato[t.x+1][t.y]);
		}
		// 왼쪽
		if (t.y - 1 >= 0 && tomato[t.x][t.y-1].cond == 0) {
			tomato[t.x][t.y-1].cond = t.cond+1;
			q.push(tomato[t.x][t.y-1]);
		// 오른쪽
		if (t.y + 1 <= m - 1 && tomato[t.x][t.y + 1].cond == 0) {
			tomato[t.x][t.y + 1].cond = t.cond + 1;
			q.push(tomato[t.x][t.y + 1]);
		}
	}

	// 안 익은 토마토가 있는지 검사
	bool tomatoComplete = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tomato[i][j].cond == 0) tomatoComplete = false;
		}
		if (!tomatoComplete) break;
	}

	// cond-1하는 이유는 처음에 cond=1이기 때문이다.
	if (tomatoComplete) cout << tomato[t.x][t.y].cond - 1;
	else cout << "-1";
	return 0;
}