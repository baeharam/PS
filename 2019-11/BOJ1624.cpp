#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;
const int MAX_SIZE = 2000;

int N;
int D[MAX_SIZE + 1];
vector<int> A,B;

bool cover(int l, int r)
{
	if(r - l < 2) return true;
	l = B[l], r = B[r];
	int s = INF, e = -INF;
	for(int i=0; i<N; i++){
		if(l > A[i] || r < A[i]) continue;
		if(s < A[i] && A[i] < e) return false;
		s = min(s, A[i]);
		e = max(e, A[i]);
	}
	return true;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	A.resize(N);
	B.resize(N);
	for(int i=0; i<N; i++){
		cin >> A[i];
		B[i] = A[i];
	}

	B.erase(unique(B.begin(),B.end()), B.end());
	sort(B.begin(), B.end());

	int NB = (int) B.size();

	fill(D, D + NB, INF);

	for(int i=0; i<NB; i++){
		if(cover(0,i)){
			D[i] = 1;
			continue;
		}
		for(int j=i; j>=0; j--){
			if(!cover(j, i)) continue;
			D[i] = min(D[i], D[j - 1] + 1);
		}
	}

	cout << D[NB - 1] << '\n';

	return 0;
}