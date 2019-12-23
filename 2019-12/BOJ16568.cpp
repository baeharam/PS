#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000005;
const int inf = 2e9;
int N,a,b;
int dp[4][maxn];

int solve(int opt, int nth)
{
	if(nth == N) return 0;
	if(nth > N) return inf;
	int &ret = dp[opt][nth];
	if(ret != -1) return ret;
	ret = inf;
	for(int i=1; i<=3; i++){
		int d = (i==1 ? 0 : (i==2 ? a : b));
		ret = min(ret, solve(i,nth+d+1) + 1);
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> a >> b;
	memset(dp,-1,sizeof(dp));
	cout << solve(0,0) << '\n';
	return 0;
}