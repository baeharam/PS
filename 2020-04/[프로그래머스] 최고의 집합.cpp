#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n, int s) {
	vector<int> ans;
	int q = s / n, r = s % n;
	if(!q) ans.push_back(-1);
	else {
		for(int i=0; i<n - r; ++i)
			ans.push_back(q);
		for(int i=0; i<r; ++i)
			ans.push_back(q + 1);
	}
	return ans;
}