#include <bits/stdc++.h>
using namespace std;

const int maxn = 55;
int N;
char b[maxn][maxn];

int check()
{
	int ans = 0, temp = 0;
	for(int i=1; i<=N; i++){
		temp = 1;
		for(int j=2; j<=N; j++){
			if(b[i][j] == b[i][j-1]) temp++;
			else temp = 1;
			ans = max(temp, ans);
		}
	}
	for(int j=1; j<=N; j++){
		temp = 1;
		for(int i=2; i<=N; i++){
			if(b[i][j] == b[i-1][j]) temp++;
			else temp = 1;
			ans = max(temp, ans);
		}
	}
	return ans;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for(int i=1; i<=N; i++){
		string s;
		cin >> s;
		for(int j=0; j<(int)s.size(); j++){
			b[i][j+1] = s[j];
		}
	}

	int ans = 0, temp = 0;
	for(int i=1; i<=N; i++){
		for(int j=1; j<N; j++){
			if(b[i][j] == b[i][j+1]) continue;
			swap(b[i][j],b[i][j+1]);
			ans = max(ans, check());
			swap(b[i][j],b[i][j+1]);
		}
	}
	for(int i=1; i<N; i++){
		for(int j=1; j<=N; j++){
			if(b[i][j] == b[i+1][j]) continue;
			swap(b[i][j],b[i+1][j]);
			ans = max(ans, check());
			swap(b[i][j],b[i+1][j]);
		}
	}
	cout << ans << '\n';

	return 0;
}