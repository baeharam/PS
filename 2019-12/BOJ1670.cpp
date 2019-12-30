#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
const ull mod = 987654321ULL;
int N;
ull dp[10001];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	dp[0] = dp[2] = 1ULL;

	// dp[i] = i명이 완벽하게 악수하는 경우의 수
	// 1번 기준, 1번이 j번과 악수할 때 나머지 애들 악수하는 경우 생각하기.
	for(int i=4; i<=N; i+=2){
		for(int j=2; j<=i; j+=2){
			dp[i] += (dp[i-j] * dp[j-2]) % mod;
			dp[i] %=  mod;
		}
	}
	cout << dp[N] % mod << '\n';
	return 0;
}