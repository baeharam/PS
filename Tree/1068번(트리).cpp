#include <cstdio>
#include <vector>
using namespace std;

int n, t, e, l;
vector<int> tree[50];

void dfs(int node)
{
	for (int i = 0; i < tree[node].size(); i++) dfs(tree[node][i]);
	tree[node].clear();
	tree[node].push_back(-1);
}


int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t); if (t == -1) continue;
		tree[t].push_back(i);
	}
	scanf("%d", &e);

	// 지울 노드의 subtree 제거
	dfs(e);

	for (int i = 0; i < n; i++) {
		if (!tree[i].size() || 
			(tree[i].size() == 1 && tree[i][0] == e)) l++;
	}

	printf("%d", l);
	return 0;
}
