#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

typedef pair<int, int> p;
vector<p> g[805];
bool visit[805];
priority_queue<p, vector<p>, greater<p>> q;
int n, e, a, b, c, v1, v2, p1, p2, p3, p4, p5;
const int INF = 2100000000;

int Dijkstra(int s, int d)
{	
	q.push(p(0, s));
	
	while (!q.empty()) {
		p t = q.top(); q.pop();
		visit[t.second] = true;
		if (t.second == d) {
			while (!q.empty()) q.pop();
			for (int i = 1; i <= n; i++) visit[i] = false;
			return t.first;
		}
		for (int i = 0; i < g[t.second].size(); i++) {
			if(!visit[g[t.second][i].second])
				q.push(p(g[t.second][i].first + t.first, g[t.second][i].second));
		}
	}
	return INF;
}

int main(void)
{
	scanf("%d%d", &n, &e);
	for (int i = 0; i < e; i++) {
		scanf("%d%d%d", &a, &b, &c);
		g[a].push_back(p(c, b));
		g[b].push_back(p(c, a));
	}
	scanf("%d%d", &v1, &v2);

	p1 = Dijkstra(1, v1); p3 = Dijkstra(v1, v2); p2= Dijkstra(v2, n);
	p4 = Dijkstra(1, v2); p3 = Dijkstra(v2, v1); p5= Dijkstra(v1, n);

	if (p3 == INF || p1 == INF || p2 == INF || p4 == INF || p5 == INF) printf("-1");
	else p1 + p2 + p3 < p3 + p4 + p5 ? printf("%d", p1 + p2 + p3) : printf("%d", p3 + p4 + p5);
	
	return 0;
}