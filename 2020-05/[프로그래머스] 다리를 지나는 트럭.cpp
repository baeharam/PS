#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int ct, cw, ft, fw, ww, tidx;
queue<pii> q;

int solution(int bl, int w, vector<int> tw){
	ct = 1, cw = tw[tidx++];
	q.push({ct, cw});

	while(!q.empty()){
		++ct;
		pii f = q.front();
		ft = f.first, fw = f.second;
		if(ct - ft == bl){
			q.pop();
			cw -= fw;
		}
		if(tidx < (int)tw.size() && cw + tw[tidx] <= w){
			q.push({ct, tw[tidx]});
			cw += tw[tidx];
			++tidx;
		}
	}
	return ct;
}
