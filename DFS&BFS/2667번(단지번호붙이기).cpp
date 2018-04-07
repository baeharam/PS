#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

int danji[26][26];
bool visited[26][26];

struct Pos {
	int x;
	int y;
};

std::queue<Pos> path;

int BFS(Pos begin, int n)
{
	path.push(begin);
	visited[begin.x][begin.y] = true;
	int x = 0, y = 0;
	int num = 0;

	while (!path.empty()) {
		x = path.front().x; y = path.front().y;
		num++;
		path.pop();
		if (x - 1 >= 1 && danji[x - 1][y] == 1 && !visited[x - 1][y]) {
			Pos discover = { x - 1,y };
			path.push(discover);
			visited[x - 1][y] = true;
		}
		if (x + 1 <= n && danji[x + 1][y] == 1 && !visited[x + 1][y]) {
			Pos discover = { x + 1,y };
			path.push(discover);
			visited[x + 1][y] = true;
		}
		if (y - 1 >= 1 && danji[x][y - 1] == 1 && !visited[x][y - 1]) {
			Pos discover = { x,y - 1 };
			path.push(discover);
			visited[x][y - 1] = true;
		}
		if (y + 1 <= n && danji[x][y + 1] == 1 && !visited[x][y + 1]) {
			Pos discover = { x,y+1 };
			path.push(discover);
			visited[x][y + 1] = true;
		}
	}

	return num;
}

int main(void)
{
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%1d", &danji[i][j]);
			visited[i][j] = false;
		}
	}

	std::vector<int> numHouse;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (danji[i][j] == 1 && !visited[i][j]) {
				Pos temp = { i,j };
				numHouse.push_back(BFS(temp,n));
			}
		}
	}

	std::sort(numHouse.begin(), numHouse.end());

	printf("%d\n", numHouse.size());
	for (int i = 0; i < numHouse.size(); i++) printf("%d\n", numHouse[i]);
	return 0;
}