#include <bits/stdc++.h>
using namespace std;

const int maxn = 1001;
int T,N;
int dp[maxn];
vector<int> qq;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	int mv = 0;
	while(T--){
		cin >> N;
		qq.push_back(N);
		mv = max(mv, N);
	}

	for(int i=1; i<=mv; i++) dp[i] = 1;
	for(int i=2; i<=mv; i++){
		if(i % 2 == 0){
			dp[i] += dp[i/2];
		}
		for(int j=1; j<i; j++){
			if((i-j) % 2) continue;
			dp[i] += dp[(i-j)/2];
		}
	}

	for(int q : qq) cout << dp[q] << '\n';

	return 0;
}