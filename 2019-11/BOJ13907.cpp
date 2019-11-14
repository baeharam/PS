#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

using ll = long long;
using P = pair<int,ll>;
using PP = pair<P, int>;

const int VERTEX_SIZE = 1000;
const ll INF = 2e9;

vector<P> g[VERTEX_SIZE + 1];
int N,M,K,S,D,a,b,w,p;
ll dist[VERTEX_SIZE + 1][VERTEX_SIZE + 1];
struct cmp{ bool operator()(PP& p1, PP& p2) { return p1.first.second > p2.first.second; }};
priority_queue<PP, vector<PP>, cmp> pq;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K >> S >> D;
	for(int i=0; i<M; i++){
		cin >> a >> b >> w;
		g[a].push_back(P(b,w));
		g[b].push_back(P(a,w));
	}

	for(int i=1; i<=N; i++){
		for(int j=0; j<=N-1; j++){
			dist[i][j] = INF;
		}
	}

	for(int i=0; i<=N-1; i++) dist[S][i] = 0LL;
	pq.push(PP(P(S,0LL),0));

	while(!pq.empty()){
		PP cur = pq.top(); pq.pop();
		int v = cur.first.first;
		ll d = cur.first.second;
		int b = cur.second;
		if(d > dist[v][b]) continue;
		for(P next : g[v]){
			int nv = next.first;
			ll nd = next.second;
			if(dist[v][b] + nd < dist[nv][b+1]){
				dist[nv][b+1] = dist[v][b] + nd;
				pq.push(PP(P(nv, dist[nv][b+1]), b+1));
			}
		}
	}

	ll ans = INF;
	for(int i=0; i<=N-1; i++) ans = min(ans, dist[D][i]);
	cout << ans << '\n';

	while(K--){
		cin >> p;
		ans = INF;
		for(int i=0; i<=N-1; i++){
			if(dist[D][i] == INF) continue;
			dist[D][i] += (i * p * 1LL);
			ans = min(ans, dist[D][i]);
		}
		cout << ans << '\n';
	}

	return 0;
}