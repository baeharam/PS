#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct vertex {
	int v1;
	int v2;
	int w;
};

vector<vertex> city[100005];
bool visit[100005];
int n, m, c1, c2, w, s, e, dist[100005];
priority_queue<vertex> q;
vertex p;
const int INF = 2100000000;

bool operator<(vertex p1, vertex p2) {
	return dist[p1.v1] > dist[p2.v1];
}

void Dijkstra()
{
	q.push({ s,s,0 });

	while (!q.empty()) {
		p = q.top(); q.pop();
		visit[p.v1] = true;
		
		for (int i = 0; i < city[p.v1].size(); i++) {
			int v2 = city[p.v1][i].v2, w = city[p.v1][i].w, v1 = p.v1;
			if (!visit[v2] && dist[v1]+w<dist[v2]) {
				dist[v2] = dist[v1] + w;
				q.push({ v2,v2,0 });
			}
		}
	}
}



int main(void)
{
	scanf("%d %d", &n, &m);


	for (int i = 1; i <= n; i++) dist[i] = INF;

	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &c1, &c2, &w);
		city[c1].push_back({ c1,c2,w });
	}


	scanf("%d%d", &s, &e); dist[s] = 0; visit[s] = true;

	Dijkstra();
	printf("%d", dist[e]);
	return 0;
}