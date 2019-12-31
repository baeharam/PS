#include <bits/stdc++.h>
using namespace std;

using P = pair<int,int>;
using PP = pair<P,P>;
using ll = long long;
const int maxn = 105;
int N,M,K,a,b,c,d;
ll dp[maxn][maxn];
vector<PP> pos;

ll f(int x, int y, int count, P before)
{
	if(x > N || y > M) return 0;
	for(PP &pp : pos){
		int sx = pp.first.first;
		int sy = pp.first.second;
		int ex = pp.second.first;
		int ey = pp.second.second;
		if(ex == x && ey == y 
			&& sx == before.first && sy == before.second)
			return 0;
		if(sx == x && sy == y
			&& ex == before.first && ey == before.second)
			return 0;
	}
	if(count > N + M) return 0;
	if(x == N && y == M) return 1;

	ll &ret = dp[x][y];
	if(ret != -1) return ret;

	ret = f(x+1,y,count+1,{x,y});
	ret += f(x,y+1,count+1,{x,y});
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N >> M >> K;
	for(int i=0; i<K; i++){
		cin >> a >> b >> c >> d;
		pos.push_back((PP){(P){a,b},(P){c,d}});
	}
	memset(dp, -1, sizeof(dp));
	cout << f(0,0,0,{0,0}) << '\n';
	return 0;
}