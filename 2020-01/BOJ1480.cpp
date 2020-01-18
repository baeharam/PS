#include <bits/stdc++.h>
using namespace std;

int N,M,C;
int jewel[14];
int dp[11][21][(1<<13)-1];

int f(int nth, int weight, int state)
{
	if(nth > M) return 0;

	int &ret = dp[nth][weight][state];
	if(ret != -1) return ret;

	ret = 0;
	for(int i=0; i<N; i++){
		int visit = state & (1 << i);
		if(visit) continue;
		if(weight + jewel[i] > C) {
			ret = max(ret, f(nth+1, 0, state));
		} else {
			int newState = state | (1 << i);
			ret = max(ret, f(nth, weight+jewel[i], newState) + 1);
		}
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> C;
	for(int i=0; i<N; i++)
		cin >> jewel[i];
	memset(dp, -1, sizeof(dp));
	cout << f(1,0,0) << '\n';

	return 0;
}