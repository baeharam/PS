#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;
int T,W,ans;
int a[maxn];
int dp[maxn][35][4];

int main(void)
{
	cin >> T >> W;
	for(int i=1; i<=T; i++) cin >> a[i];
	for(int i=1; i<=T; i++){
		for(int j=0; j<=W; j++){
			if(j%2)
				dp[i][j][2] = max(dp[i-1][j][2], !j ? 0 : dp[i-1][j-1][1]) + (a[i] == 2);
			else
				dp[i][j][1] = max(dp[i-1][j][1], !j ? 0 : dp[i-1][j-1][2]) + (a[i] == 1);
		}
	}
	for(int i=0; i<=W; i++)
		ans = max(ans, max(dp[T][i][1],dp[T][i][2]));
	cout << ans << '\n';
	return 0;
}