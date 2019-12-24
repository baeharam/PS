#include <bits/stdc++.h>
using namespace std;

const int maxn = 21;
int n,a,b,l;
int input[maxn];
int dp[maxn][maxn][maxn];

int solve(int nth, int f, int s)
{
	if(nth > l) return 0;
	int &ret = dp[nth][f][s];
	if(ret != -1) return ret;

	int target = input[nth];

	int move = abs(target - f);
	ret = solve(nth+1, target, s) + move;

	move = abs(target - s);
	ret = min(ret, solve(nth+1, f, target) + move);

	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> a >> b >> l;
	for(int i=1; i<=l; i++) cin >> input[i];

	memset(dp, -1, sizeof(dp));
	cout << solve(1,a,b) << '\n';

	return 0;
}