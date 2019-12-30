#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<int,int>;
const int maxn = 100005;
const ll inf = 2e14;
int N,X,Y;
ll dp[maxn][5];
int dx[5] = {0,-1,1,0,0};
int dy[5] = {0,0,0,-1,1};
P pos[maxn];

ll f(int nth, int type, P cur)
{
	if(nth > N) return 0LL;
	ll &ret = dp[nth][type];
	if(ret != -1) return ret;

	int cx = cur.first;
	int cy = cur.second;

	ret = inf;
	for(int i=0; i<5; i++){
		int _dx = pos[nth].first + dx[i];
		int _dy = pos[nth].second + dy[i];
		if(_dx <= 0 || _dx > 100000 || _dy <= 0 || _dy > 100000) continue;
		ll d = abs(cx - _dx) + abs(cy - _dy);
		ret = min(ret, f(nth+1,i,{_dx,_dy}) + d);
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> X >> Y;

	for(int i=1; i<=N; i++)
		cin >> pos[i].first >> pos[i].second;
	memset(dp, -1, sizeof(dp));
	cout << f(1,0,{X,Y}) << '\n';
	return 0;
}