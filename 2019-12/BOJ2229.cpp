#include <bits/stdc++.h>
using namespace std;

const int maxn = 1001;
int N;
int dp[maxn],a[maxn];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for(int i=1; i<=N; i++) cin >> a[i];
	for(int i=2; i<=N; i++){
		int minv = a[i];
		int maxv = a[i];
		for(int j=i-1; j>=0; j--){
			int score = abs(minv - maxv);
			dp[i] = max(dp[i], dp[j] + score);
			minv = min(minv, a[j]);
			maxv = max(maxv, a[j]);
		}
	}
	cout << dp[N] << '\n';
	return 0;
}