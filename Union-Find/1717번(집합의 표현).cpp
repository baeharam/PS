#include <cstdio>
using namespace std;

struct Disjointset {
	int parent;
	int rank;
};
Disjointset n_set[1000005];

int Find(int x)
{
	if (x = n_set[x].parent) return x;
	else return n_set[x].parent = Find(n_set[x].parent);
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	if (x == y) return;
	if (n_set[x].rank < n_set[y].rank) n_set[x].parent = y;
	else n_set[y].parent = x;
	if (n_set[x].rank == n_set[y].rank) n_set[x].rank++;	
}

int main(void)
{
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i <= n; i++) {
		n_set[i].parent = i;
		n_set[i].rank = 0;
	}
	int op, a, b;
	while (m--) {
		scanf("%d%d%d", &op, &a, &b);
		if (op == 0) Union(a, b);
		else if (Find(a) == Find(b)) printf("YES\n");
		else if (Find(a)!=Find(b)) printf("NO\n");
	}
	return 0;
}