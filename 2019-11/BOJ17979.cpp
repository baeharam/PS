#include <bits/stdc++.h>
using namespace std;

using P = pair<int,int>;
using PP = pair<int, P>;
const int tsize = 100;
const int nsize = 10000;
int M,N,s,e,t;
int cost[tsize + 1];
int dp[nsize + 1];
vector<PP> q;

int main(void)
{
	cin >> M >> N;
	for(int i=1; i<=M; i++)
		cin >> cost[i];
	for(int i=0; i<N; i++){
		cin >> s >> e >> t;
		q.push_back(PP(s,P(e,t)));
	}

	sort(q.begin(), q.end());

	dp[0] = (q[0].second.first - q[0].first) * cost[q[0].second.second];
	int ans = dp[0];
	for(int i=1; i<N; i++){
		int is = q[i].first;
		int ie = q[i].second.first;
		int it = q[i].second.second;
		int c = (ie - is) * cost[it];
		dp[i] = c;

		for(int j=i-1; j>=0; j--){
			int js = q[j].first;
			int je = q[j].second.first;
			int jt = q[j].second.second;
			if(je > is) continue;
			dp[i] = max(dp[i], dp[j] + c);
		}
		ans = max(ans, dp[i]);
	}

	cout << ans << '\n';

	return 0;
}