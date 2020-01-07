#include <bits/stdc++.h>
using namespace std;

const int inf = -1e9;
const int maxn = 405;
int N;
int dp[maxn][maxn][maxn];
int input[3][maxn];

/*
	위에서 upper개가 남아있고
	아래에 lower개가 남아있을 때
	col개의 열을 이미 채운 상태인 경우에 최댓값.
	오른쪽부터 왼쪽으로 채워간다.
*/

int f(int upper, int lower, int col)
{
	if(N - col < max(upper,lower)) return inf;
	if(!upper || !lower) return 0;

	int &ret = dp[upper][lower][col];
	if(ret != inf) return ret;

	ret = f(upper-1,lower-1,col+1) + input[1][upper]*input[2][lower];
	ret = max(ret, f(upper-1,lower,col+1));
	ret = max(ret, f(upper,lower-1,col+1));
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	int uidx = 1, lidx = 1, temp;
	for(int i=1; i<=2; i++){
		for(int j=1; j<=N; j++){
			cin >> temp;
			if(temp)
				input[i][i==1?uidx++:lidx++] = temp;
		}
	}
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			for(int k=0; k<=N; k++){
				dp[i][j][k] = inf;
			}
		}
	}
	cout << f(uidx-1,lidx-1,0) << '\n';
	return 0;
}