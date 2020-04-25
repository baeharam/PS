#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> stones, int k) {
	int l = 1, r = 2e8, ans = 0;
	while(l <= r){
		int m = (l + r) / 2, zero = 0, maxZero = 0;
		for(int i=0; i<(int)stones.size(); ++i){
			if(stones[i] < m){
				++zero;
			} else{
				maxZero = max(maxZero, zero);
				zero = 0;
			}
		}
		maxZero = max(maxZero, zero);
		if(maxZero >= k) r = m - 1;
		else{
			ans = m;
			l = m + 1;
		}
	}
	return ans;
}