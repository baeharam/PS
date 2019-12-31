#include <bits/stdc++.h>
using namespace std;

const int maxn = 3005;
const int inf = -2e9;
int A,B,C,lenX,lenY;
int dp[maxn][maxn];
string X,Y;

int f(int xx, int yy)
{
	if(xx > lenX || yy > lenY) return inf;
	if(xx == lenX && yy == lenY) return 0;

	int &ret = dp[xx][yy];
	if(ret != inf) return ret;

	ret = f(xx+1, yy+1) + (X[xx] == Y[yy] ? A : C);
	ret = max(ret, f(xx, yy+1) + B);
	ret = max(ret, f(xx+1, yy) + B);
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> A >> B >> C >> X >> Y;
	lenX = (int)X.size();
	lenY = (int)Y.size();
	int maxLen = max(lenX, lenY);
	for(int i=0; i<=maxLen; i++){
		for(int j=0; j<=maxLen; j++){
			dp[i][j] = inf;
		}
	}
	cout << f(0,0) << '\n';
	return 0;
}