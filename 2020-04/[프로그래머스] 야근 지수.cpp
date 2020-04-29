#include <bits/stdc++.h>
using namespace std;
using ll = long long;

priority_queue<ll> pq;

ll solution(int n, vector<int> works) {
	for(int w : works) pq.push((ll)w);
	while(n) {
		ll c = pq.top(); pq.pop();
		if(!c) break;
		--c; --n;
		pq.push(c);
	}
	ll ans = 0LL;
	while(!pq.empty()){
		ll c = pq.top(); pq.pop();
		ans += c * c;
	}
	return ans;
}