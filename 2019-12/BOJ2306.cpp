#include <bits/stdc++.h>
using namespace std;

const int maxn = 505;
string s;
int dp[maxn][maxn];

int f(int l, int r)
{
	if(r-l <= 0) return 0;
	int &ret = dp[l][r];
	if(ret != -1) return ret;
	ret = 0;
	if((s[l] == 'a' && s[r] == 't') || (s[l] == 'g' && s[r] == 'c'))
		ret = f(l+1,r-1) + 2;
	for(int i=l; i<=r; i++)
		ret = max(ret, f(l,i) + f(i+1,r));
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> s;
	int len = (int)s.size();
	memset(dp, -1, sizeof(dp));
	cout << f(0,len-1) << '\n';
	return 0;
}