#include <bits/stdc++.h>
using namespace std;

const int maxn = 10005;
const int inf = 2e9;
int N,M;
int dp[maxn][201];
bool ban[maxn];

int f(int nth, int before)
{
	if(ban[nth] || nth > N) return inf;
	if(nth == N) return 0;
	int &ret = dp[nth][before];
	if(ret != -1) return ret;
	ret = inf;
	for(int i=0; i<3; i++){
		int jump = before;
		if(i == 0) jump -= 1;
		else if(i == 2) jump += 1;
		if(jump <= 0) continue;
		ret = min(ret, f(nth + jump, jump) + 1);
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for(int i=0; i<M; i++){
		int temp; cin >> temp;
		ban[temp] = true;
	}
	memset(dp, -1, sizeof(dp));
	cout << (f(2,1) == inf ? -1 : f(2,1) + 1) << '\n';
	return 0;
}