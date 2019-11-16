#include <bits/stdc++.h>
using namespace std;

int N;
int A[1005];

int main(void)
{
	cin >> N;
	A[0] = A[1] = 1;
	for(int i=2; i<=N; i++){
		int num = 1;
		while(true){
			bool pass = true;
			for(int k=1; i-2*k>=0; k++){
				if(num - A[i-k] != A[i-k] - A[i-2*k]) continue;
				pass = false;
				break;
			}
			if(pass) break;
			else{
				num++;
				continue;
			}
		}
		A[i] = num;
	}
	cout << A[N] << '\n';
	return 0;
}