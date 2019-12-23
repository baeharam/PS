#include <bits/stdc++.h>
using namespace std;

using P = pair<int,int>;
const int maxn = 105;
const int maxk = 100005;
int N,K;
int dp[maxn][maxk];
P input[maxn];

int main(void)
{
	cin >> N >> K;
	for(int i=1; i<=N; i++)
		cin >> input[i].first >> input[i].second;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=K; j++){
			if(j-input[i].first < 0)
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-input[i].first] + input[i].second);
		}
	}
	int ans = 0;
	for(int i=1; i<=K; i++)
		ans = max(ans, dp[N][i]);
	cout << ans << '\n';
	return 0;
}