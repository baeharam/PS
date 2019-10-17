#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

int town[51][51], c[101], candidate[101], n, m, ans;
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
map < pair<int, int>, vector<int>> dist;

void comb(int a, int b, int index, int target)
{
	if (b == 0) {
		for (int i = 0; i < index; i++) {
			for (int j = 1; j <= home.size(); j++) {
				int d = dist[chicken[c[i]]][j - 1];
				if (candidate[j] == -1 || candidate[j] > d)
					candidate[j] = d;
			}
		}
		int sum = 0;
		for (int i = 1; i <= home.size(); i++) sum += candidate[i];
		if (ans > sum) ans = sum;
		memset(candidate, -1, sizeof(candidate));
	}

	else if (a >= b) {
		c[index] = target;
		comb(a - 1, b - 1, index + 1, target + 1);
		comb(a - 1, b, index, target + 1);
	}
}

int main(void)
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &town[i][j]);
			if (town[i][j] == 1) home.push_back(make_pair(i, j));
			else if (town[i][j] == 2) chicken.push_back(make_pair(i, j));
		}
	}
	memset(candidate, -1, sizeof(candidate));
	ans = 2100000000;

	for (int i = 0; i < chicken.size(); i++) {
		vector<int> temp;
		for (int j = 0; j < home.size(); j++) {
			int r = chicken[i].first < home[j].first ? home[j].first - chicken[i].first
				: chicken[i].first - home[j].first;
			int c = chicken[i].second < home[j].second ? home[j].second - chicken[i].second
				: chicken[i].second - home[j].second;
			temp.push_back(r + c);
		}
		dist[chicken[i]] = temp;
	}

	comb(chicken.size(), m, 0, 0);

	printf("%d\n", ans);
	return 0;
}