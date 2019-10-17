#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

int mo[100][100], m, n, k, x1, y, x2, y2, sum;

struct coor {
	int a;
	int b;
};

std::queue<coor> q;
std::vector<int> size;


void bfs()
{
	coor s, temp;
	int x, y; sum = 0;
	while (!q.empty()) {
		s = q.front(); q.pop();
		sum++;
		x = s.a; y = s.b;
		// 위쪽
		if (x - 1 >= 0 && mo[x - 1][y] != 1) {
			temp = { x - 1,y };
			mo[x - 1][y] = 1;
			q.push(temp);
		}
		// 아래쪽
		if (x + 1 < m && mo[x + 1][y] != 1) {
			temp = { x + 1,y };
			mo[x + 1][y] = 1;
			q.push(temp);
		}
		// 왼쪽
		if (y - 1 >= 0 && mo[x][y - 1] != 1) {
			temp = { x,y - 1 };
			mo[x][y - 1] = 1;
			q.push(temp);
		}
		// 오른쪽
		if (y + 1 < n && mo[x][y + 1] != 1) {
			temp = { x,y + 1 };
			mo[x][y + 1] = 1;
			q.push(temp);
		}
	}
}

int main(void)
{
	scanf("%d%d%d", &m, &n, &k); m--;

	while (k--) {
		scanf("%d%d%d%d", &x1, &x2, &y, &y2);
		std::swap(x1, x2); x1 = m - x1;
		std::swap(y, y2); y -= 1; y2 -= 1; y = m - y;
		std::swap(x1, y);
		
		for (int i = x1; i <= y; i++) {
			for (int j = x2; j <= y2; j++) mo[i][j] = 1;
		}
	}

	m++;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (mo[i][j] != 1) {
				coor temp = { i,j };
				mo[i][j] = 1;
				q.push(temp);
				bfs();
				size.push_back(sum);
			}
		}
	}

	printf("%d\n", size.size());
	std::sort(size.begin(), size.end());
	for (int i = 0; i < size.size(); i++) printf("%d ", size[i]);

	return 0;
}