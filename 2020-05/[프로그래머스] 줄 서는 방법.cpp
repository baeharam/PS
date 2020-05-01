#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll s, q, r, fact[21];
vector<int> ans, track;

ll f(ll nn) {
	if(nn == 0 || nn == 1) return 1;
	if(fact[nn]) return fact[nn];
	return fact[nn] = f(nn - 1) * nn;
}

vector<int> solution(int n, ll k) {
	for(int i=1; i<=n; ++i) 
		track.push_back(i);
	s = f(n) / n;
	r = k % s;
	if(!r) r = s;
	q = (k - 1) / s;
	ans.push_back(track[q]);
	track.erase(track.begin() + q);
	--n;
	while(n > 1) {
		s /= n;
		q = (r - 1) / s;
		r %= s;
		if(!r) r = s;
		ans.push_back(track[q]);
		track.erase(track.begin() + q);
		--n;
	}
	ans.push_back(track[0]);
	return ans;
}

int main(void) {
	solution(20, f(20));
	for(int a : ans) printf("%d ", a);
	puts("");
	return 0;
}