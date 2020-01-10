#include <bits/stdc++.h>
using namespace std;

const int maxk = 205;
const int maxn = 4005;
const int mod = 1e6;
int T,A,S,B;
int dp[maxk][maxn];
int cc[maxk],input[maxn];

/*

dp[end][num]
= end까지 포함하고 원소의 개수가 num개인 집합을 만들 때 집합 개수.

*/
int f(int end, int num)
{
	if(end <= 0) return 0;
	int &ret = dp[end][num];
	if(ret != -1) return ret;

	ret = 0;
	// 자기 자신으로만 만들 수 있을 때 +1
	// end가 1이고 num이 2면 {1, 1}
	if(num <= cc[end]) ret++;

	// 축적하는 부분, 이전 결과값 그 대로 더해준다.
	ret += f(end-1,num);
	ret %= mod;
	for(int i=1; i<=cc[end]; i++){
		if(num - i <= 0) continue;
		// 이전 결과값 중 end의 개수 범위 내에서 사용할 수 있는 원소의 개수로,
		// 이미 계산된 값 더해준다.
		ret += f(end-1,num-i);
		ret %= mod;
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T >> A >> S >> B;
	for(int i=1; i<=A; i++){
		cin >> input[i];
		cc[input[i]]++;
	}
	memset(dp,-1,sizeof(dp));
	int ans = 0;
	for(int i=S; i<=B; i++){
		ans += f(T,i);
		ans %= mod;
	}
	cout << ans % mod << '\n';
	return 0;
}