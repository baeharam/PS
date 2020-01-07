#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;
const int mod = 1e6;
int N;
int dp[maxn][maxn][2];

// dp[l][r][flag] = 현재 선택한 사람의 키보다 작은 사람이 l명, 큰 사람이 r명일 때
// flag가 이전 2명의 사람에 대한 크고 작음을 나타낸다고 했을 때의 줄을 세우는 경우의 수

int f(int l, int r, int flag)
{
	if(!l && !r) return 1;
	int &ret = dp[l][r][flag];
	if(ret != -1) return ret;

	ret = 0;
	if(flag){
		for(int k=l; k>=1; k--){
			ret += f(l-k, r+(k-1), !flag);
			ret %= mod;
		}
	} else{
		for(int k=r; k>=1; k--){
			ret += f(l+(k-1), r-k, !flag);
			ret %= mod;
		}
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	if(N == 1){
		cout << "1\n";
		return 0;
	}
	memset(dp,-1,sizeof(dp));
	int ans = 0;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			if(i == j) continue;
			ans += f(j-1-(i<j),N-j-(i>j),i<j);
			ans %= mod;
		}
	}
	cout << ans % mod << '\n';
	return 0;
}