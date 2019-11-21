#include <bits/stdc++.h>
using namespace std;

using P = pair<int,int>;
using PP = pair<P, int>;
const int maxn = 15;
const int INF = 2e9;
int N,M,D,e;
int rr[maxn*maxn + 1];
vector<PP> archer;
vector<P> enemy, temp;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> D;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			cin >> e;
			if(e == 1) {
				temp.push_back(P(j,i));
			}
		}
	}

	for(int i=1; i<=M-2; i++){
		for(int j=i+1; j<=M-1; j++){
			for(int k=j+1; k<=M; k++){
				archer.push_back(PP(P(i,j),k));
			}
		}
	}

	enemy.resize(temp.size());
	sort(temp.begin(), temp.end());

	int ans = 0;
	for(PP pp : archer) {
		copy(temp.begin(), temp.end(), enemy.begin());
		int aa[3] = { pp.first.first, pp.first.second, pp.second };

		memset(rr, 0, sizeof(rr));
		while(true){
			bool empty = true;
			for(P e : enemy) {
				if(e.second != -1){
					empty = false;
					break;
				}
			}
			if(empty) break;

			vector<int> candidate;
			for(int i=0; i<3; i++) {
				int dd = INF, didx = -1;
				for(int j=0; j<(int)enemy.size(); j++) {
					P e = enemy[j];
					int d = abs(e.first - aa[i]) + abs(e.second - (N + 1));
					if(d > D) continue;
					if(d < dd){
						dd = d;
						didx = j;
					}
				}
				if(didx != -1)
					candidate.push_back(didx);
			}

			for(int idx : candidate) {
				rr[idx] = 1;
				enemy[idx].second = -1;
			}

			for(P &e : enemy) {
				if(e.second == -1 || e.second == N){
					e.second = -1;
					continue;
				}
				e.second += 1;
			}
		}
		int r = 0;
		for(int i=0; i<(int)temp.size(); i++)
			r += rr[i];
		ans = max(ans, r);
	}

	cout << ans << '\n';

	return 0;
}