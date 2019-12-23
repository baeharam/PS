#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;
int N;
int dp[maxn];
string s;
string a[maxn];

int solve(int pos)
{
	if(pos >= (int)s.size()) return 1;
	int &ret = dp[pos];
	if(ret != -1) return ret;

	ret = 0;
	int len = -1;
	for(int i=1; i<=N; i++){
		len = (int)a[i].size();
		if(!a[i].compare(s.substr(pos,len))){
			ret = solve(pos+len);			
		}
		if(ret) break;
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> s >> N;
	for(int i=1; i<=N; i++) cin >> a[i];
	memset(dp,-1,sizeof(dp));
	cout << solve(0) << '\n';
	return 0;
}