#include <bits/stdc++.h>
using namespace std;

using P = pair<int,int>;
const int maxn = 105;
const int maxk = 305;
int N,M,K;
int dp[maxn][maxk][maxk];
P order[maxk];

int solve(int nth, int bb, int ff)
{
	if(bb < 0 || ff < 0) return -1;
	if(nth > N || bb == 0 || ff == 0) return 0;
	int &ret = dp[nth][bb][ff];
	if(ret != -1) return ret;
	int _bb = order[nth].first;
	int _ff = order[nth].second;
	ret = solve(nth+1,bb,ff);
	ret = max(ret, solve(nth+1,bb-_bb,ff-_ff) + 1);
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M >> K;
	for(int i=1; i<=N; i++)
		cin >> order[i].first >> order[i].second;
	memset(dp,-1,sizeof(dp));
	cout << solve(1,M,K) << '\n';
	return 0;
}