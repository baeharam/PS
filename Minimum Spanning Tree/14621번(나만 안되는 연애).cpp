#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
	int u;
	int v;
	int d;

	bool operator<(const Edge &rhs) {
		return d < rhs.d;
	}
};

char sc[1001];
int n, m, ans, cnt, parent[1001];
vector<Edge> e;

int Find(int u)
{
	if (parent[u] == u) return u;
	else return parent[u] = Find(parent[u]);
}

void Kruskal()
{
	for (int i = 0; i < e.size(); i++) {
		Edge edge = e[i];
		int pu = Find(edge.u), pv = Find(edge.v);
		if (pu != pv) {
			parent[pu] = edge.v;
			ans += edge.d;
			cnt++;
		}
	}
}


int main(void)
{
	scanf("%d%d", &n, &m);
	fgetc(stdin);
	int i = 1;
	while (i <= n) {
		scanf("%c", &sc[i]);
		if (sc[i] != ' ') {
			parent[i] = i;
			i++;
		}
	}

	int u, v, d;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &u, &v, &d);
		if (sc[u] != sc[v])
			e.push_back({ u, v, d });
	}

	sort(e.begin(), e.end());
	Kruskal();

	cnt != (n - 1) ? printf("-1\n") : printf("%d\n", ans);
	return 0;
}