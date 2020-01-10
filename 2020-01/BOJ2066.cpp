#include <bits/stdc++.h>
using namespace std;

const int maxg = 9;
const int maxs = 4;
using P = pair<int,int>;
string card[maxg + 1][maxs + 1];
double dp[5][5][5][5][5][5][5][5][5];

double f(int g1,int g2,int g3,int g4,int g5,int g6,int g7,int g8, int g9)
{
	if(!g1 && !g2 && !g3 && !g4 && !g5 && !g6 && !g7 && !g8 && !g9) return 1.0;
	double &ret = dp[g1][g2][g3][g4][g5][g6][g7][g8][g9];
	if(ret != -1.0) return ret;

	vector<P> comb;
	int cur[maxg+1] = {-1,g1,g2,g3,g4,g5,g6,g7,g8,g9};
	for(int i=1; i<maxg; i++){
		if(!cur[i]) continue;
		char t = card[i][cur[i]][0];
		for(int j=i+1; j<=maxg; j++){
			if(!cur[j]) continue;
			char s = card[j][cur[j]][0];
			if(t != s) continue;
			comb.push_back((P){i,j});
		}
	}

	if(!(int)comb.size()) return 0;
	double percent = 1.0/(double)comb.size();
	ret = 0.0;
	int t[maxg+1];
	for(P p : comb){
		copy(cur,cur+maxg+1,t);
		t[p.first]--;
		t[p.second]--;
		ret += f(t[1],t[2],t[3],t[4],t[5],t[6],t[7],t[8],t[9])*percent;
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for(int i=1; i<=maxg; i++){
		for(int j=1; j<=maxs; j++){
			cin >> card[i][j];
		}
	}
	fill(&dp[0][0][0][0][0][0][0][0][0],&dp[0][0][0][0][0][0][0][0][0]+1953125,-1);
	cout << f(4,4,4,4,4,4,4,4,4) << '\n';
	return 0;
}