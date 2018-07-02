#include <cstdio>
#include <vector>
#include <algorithm>

// 가중치를 위해 구조체를 써야 하는가? 일단 써보자.
struct node {
	int v;
	int weight;
};

std::vector<node> tree[10005];
int dist[10005];
bool visit[10005];
int p, c, w, n, max, maxi;

void dfs(int s, int d)
{
	visit[s] = true;
	for (int i = 0; i < tree[s].size(); i++) {
		if(!visit[tree[s][i].v])
			dfs(tree[s][i].v, d + tree[s][i].weight);
	}

	dist[s] = d;
	if (d > max){
		max = d;
		maxi = s;
	}
}

int main(void)
{
	scanf("%d", &n); 
	for(int i=1; i<=n-1; i++) {
		scanf("%d%d%d", &p, &c, &w);
		node temp = { c,w };
		tree[p].push_back(temp);
		temp = { p,w };
		tree[c].push_back(temp);
	}

	dfs(1, 0); max = 0;
	for (int i = 1; i <= n; i++) visit[i] = false;
	dfs(maxi, 0);

	printf("%d", dist[maxi]);

	return 0;
}