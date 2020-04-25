#include <bits/stdc++.h>
using namespace std;

using ll = long long;
map<ll,ll> m;

ll find(ll v){
	if(!m[v]) return v;
	return m[v] = find(m[v]);
}

vector<ll> solution(ll k, vector<ll> room_number) {
	vector<ll> ans;
	for(ll r : room_number){
		if(!m[r]){
			ans.push_back(r);
			m[r] = find(r+1);
		} else{
			ll pr = find(r);
			ans.push_back(pr);
			m[pr] = find(pr+1);
		}
	}
	return ans;
}