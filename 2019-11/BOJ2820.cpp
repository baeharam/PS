#include <bits/stdc++.h>
using namespace std;

using P = pair<int,int>;
using ll = long long;
const int maxn = 500000;
int N,M,a,b,midx;
ll x;
ll cost[maxn + 1];
int visited[maxn + 1];
int idx[maxn + 1];
int ee[maxn + 1];
vector<int> g[maxn + 1],dfsTree;
vector<ll> segTree,lazy;
char type;

void makeTreeByDFS(int v){
	visited[v] = 1;
	dfsTree.push_back(v);
	for(int next : g[v]){
		if(visited[next]) continue;
		makeTreeByDFS(next);
	}
}

void initeeByDFS(int v){
	visited[v] = 1;
	midx = max(midx, idx[v]);
	for(int next : g[v]){
		if(visited[next]) continue;
		initeeByDFS(next);
	}
	ee[v] = midx;
}

ll init(int s, int e, int node)
{
	if(s == e) return segTree[node] = cost[dfsTree[s]];
	return segTree[node] = init(s, (s+e)/2, node*2) + init((s+e)/2+1, e, node*2+1);
}

void propagate(int s, int e, int node)
{
	if(lazy[node]){
		segTree[node] += (e-s+1)*lazy[node];
		if(s != e){
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		lazy[node] = 0LL;
	}
}

void update(int s, int e, int l, int r, int node, ll value)
{
	propagate(s, e, node);
	if(s > r || e < l) return;
	if(l <= s && e <= r){
		segTree[node] += (e-s+1)*value;
		if(s != e){
			lazy[node*2] += value;
			lazy[node*2+1] += value;
		}
		return;
	}
	update(s, (s+e)/2, l, r, node*2, value);
	update((s+e)/2+1, e, l, r, node*2+1, value);
	segTree[node] = segTree[node*2] + segTree[node*2+1];
}

ll query(int s, int e, int l, int r, int node)
{
	propagate(s, e, node);
	if(s > r || e < l) return 0LL;
	if(l <= s && e <= r) return segTree[node];
	return query(s,(s+e)/2,l,r,node*2) + query((s+e)/2+1,e,l,r,node*2+1);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	cin >> cost[1];
	for(int i=2; i<=N; i++){
		cin >> a >> b;
		cost[i] = a;
		g[b].push_back(i);
	}
	makeTreeByDFS(1);
	int n = (int)dfsTree.size();
	for(int i=0; i<n; i++)
		idx[dfsTree[i]] = i;
	memset(visited, 0, sizeof(visited));
	initeeByDFS(1);

	segTree.resize(4 * n);
	lazy.resize(4 * n);
	init(0, n-1, 1);

	while(M--){
		cin >> type;
		if(type == 'p'){
			cin >> a >> x;
			if(!(int)g[a].size()) continue;
			update(0, n-1, idx[g[a][0]], ee[a], 1, x);
		} else{
			cin >> a;
			cout << query(0, n-1, idx[a], idx[a], 1) << '\n';
		}
	}

	return 0;
}