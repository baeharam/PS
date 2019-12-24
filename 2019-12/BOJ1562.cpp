#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9;
int N;
int dp[105][10][1<<10];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	for(int i=1; i<=9; i++)
		dp[1][i][1<<i] = 1;

	for(int i=2; i<=N; i++){
		for(int j=0; j<=9; j++){
			int mask = 1 << j;
			for(int k=0; k<(1<<10); k++){
				if(j > 0){
					dp[i][j][k|mask] += dp[i-1][j-1][k];
					dp[i][j][k|mask] %= mod;
				}	
				if(j < 9){
					dp[i][j][k|mask] += dp[i-1][j+1][k];
					dp[i][j][k|mask] %= mod;
				}
			}
		}
	}

	int ans = 0;
	for(int i=0; i<=9; i++){
		ans += dp[N][i][(1<<10)-1] % mod;
		ans %= mod;
	}

	cout << ans % mod << '\n';

	return 0;
}