#include <bits/stdc++.h>
using namespace std;

string s1,s2;
int len1,len2;
int dp[4005][4005];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> s1 >> s2;
	len1 = (int)s1.size();
	len2 = (int)s2.size();

	int ans = 0;
	for(int i=0; i<len1; i++){
		for(int j=0; j<len2; j++){
			if(s1[i] != s2[j]) continue;
			dp[i][j]++;
			if(i-1 < 0 || j-1 < 0) continue;
			dp[i][j] += dp[i-1][j-1];
			ans = max(ans, dp[i][j]);
		}
	}

	cout << ans << '\n';

	return 0;
}