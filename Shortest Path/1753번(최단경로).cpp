#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

struct Vertex {
	int v;
	int w;
	int d;
};
	

const int INF = 2100000000;
vector<vector<Vertex>> graph;
priority_queue<Vertex> q;
vector<Vertex> dq;

bool operator<(Vertex v1, Vertex v2)
{
	return v1.d > v2.d;
}

void Dijkstra()
{
	bool *S = new bool[graph.size()];
	for (int i = 1; i <= graph.size() - 1; i++) {
		S[i] = false;
		q.push(dq[i]);
	}

	while (!q.empty()) {
		Vertex u = q.top(); q.pop();
		S[u.v] = true;
		for (int i = 0; i < graph[u.v].size(); i++) {
			int v = graph[u.v][i].v;
			if (!S[v] && dq[u.v].d + graph[u.v][i].w < dq[v].d) {
				dq[v].d = dq[u.v].d + graph[u.v][i].w;
				q.push(dq[v]);
			}
		}

	}
	delete S;
}

int main(void)
{
	int v, e, v1, v2, w;
	scanf("%d%d", &v, &e);
	int begin; scanf("%d", &begin);
	graph.resize(v+1);
	// 인접리스트 형식으로 구현해서 구조체 집어넣기!
	for (int i = 0; i < e; i++) {
		scanf("%d%d%d", &v1, &v2, &w);
		Vertex vertex = { v2,w };
		graph[v1].push_back(vertex);
	}

	dq.resize(v + 1);

	for (int i = 1; i <= v; i++) {
		Vertex distance; distance.w = 0; distance.v = i;
		if (i == begin) distance.d = 0;
		else distance.d=INF;
		dq[i] = distance;
	}

	Dijkstra();

	for (int i = 1; i <= v; i++) {
		if (dq[i].d == INF) printf("INF\n");
		else printf("%d\n", dq[i].d);
	}

	return 0;
}