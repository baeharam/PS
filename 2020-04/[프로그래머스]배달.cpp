#include <bits/stdc++.h>
using namespace std;

using ll = long long;
struct info {
	int to;
	ll d; 
	bool operator<(const info& rhs) const {
		return d > rhs.d;
	}
};
priority_queue<info> pq;
const ll INF = 2e18;
ll dist[51][51];
ll dd[51];

int solution(int n, vector<vector<int>> road, int k)
{
	memset(dist, -1, sizeof(dist));
	int len = (int)road.size();
	for(int i=0; i<len; i++){
		int from = road[i][0], to = road[i][1];
		int d = road[i][2];
		if(dist[from][to] == -1 || dist[from][to] > d)
			dist[from][to] = dist[to][from] = d;
	}
	dd[1] = 0LL;
	for(int i=2; i<=n; i++) dd[i] = INF;
	pq.push((info){1,0});
	while(!pq.empty()){
		info c = pq.top(); pq.pop();
		int from = c.to, d = c.d;
		for(int i=1; i<=n; i++){
			if(dist[from][i] == -1) continue;
			if(dist[from][i] + d >= dd[i]) continue;
			dd[i] = dist[from][i] + d;
			pq.push((info){i,dd[i]});
		}
	}
	int ans = 1;
	for(int i=2; i<=n; i++) ans += (dd[i] <= k);
	return ans;
}