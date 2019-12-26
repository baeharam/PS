#include <bits/stdc++.h>
using namespace std;

using P = pair<int, int>;
const int maxn = 1001;
const int inf = 2e9;
int N,W;
int dp[maxn][maxn];
vector<P> cc;

int f(int c1, int c2, int nth)
{
	if(nth > W) return 0;
	int &ret = dp[c1][c2];
	if(ret != inf) return ret;

	int cx = cc[nth].first;
	int cy = cc[nth].second;

	int px = (c1 == 0 ? 1 : cc[c1].first);
	int py = (c1 == 0 ? 1 : cc[c1].second);
	int d = abs(cx - px) + abs(cy - py);
	ret = f(nth,c2,nth+1) + d;

	px = (c2 == 0 ? N : cc[c2].first);
	py = (c2 == 0 ? N : cc[c2].second);
	d = abs(cx - px) + abs(cy - py);
	ret = min(ret, f(c1,nth,nth+1) + d);
	return ret;
}

void tracking(int c1, int c2, int nth)
{
	if(nth > W) return;
	int px = (c1 == 0 ? 1 : cc[c1].first);
	int py = (c1 == 0 ? 1 : cc[c1].second);
	int d1 = abs(cc[nth].first - px) + abs(cc[nth].second - py);

	px = (c2 == 0 ? N : cc[c2].first);
	py = (c2 == 0 ? N : cc[c2].second);
	int d2 = abs(cc[nth].first - px) + abs(cc[nth].second - py);

	int pp1 = dp[nth][c2] + d1;
	int pp2 = dp[c1][nth] + d2;

	if(pp1 < pp2){
		cout << "1\n";
		tracking(nth,c2,nth+1);
	} else{
		cout << "2\n";
		tracking(c1,nth,nth+1);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> W;
	cc.resize(W+1);
	for(int i=1; i<=W; i++)
		cin >> cc[i].first >> cc[i].second;
	for(int i=0; i<=W; i++){
		for(int j=0; j<=W; j++){
			dp[i][j] = inf;
		}
	}

	cout << f(0,0,1) << '\n';
	tracking(0,0,1);
	return 0;
}