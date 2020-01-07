#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int N,L;
// I와 dp가 ll인 이유는 최대 2^31까지 가는데 int최댓값이 2^31-1이기 때문
ll I;
ll dp[35][35];

// dp[len][num] = 길이가 len이고 1인 비트의 개수가 num 이하일 때
// 이진수의 개수

ll f(int len, int num)
{
	if(!len || !num) return 1;
	ll &ret = dp[len][num];
	if(ret != -1) return ret;

	ret = f(len-1,num) + f(len-1,num-1);
	return ret;
}

void tracking(int len, int num, ll k)
{
	if(!len) return;
	if(!num){
		while(len--) cout << '0';
		return;
	}

	// 0/1중 어떤 걸 사용하느냐가 핵심
	ll count = f(len-1,num);
	if(k <= count){
		cout << '0';
		tracking(len-1,num,k);
	} else{
		cout << '1';
		tracking(len-1,num-1,k-count);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> L >> I;
	memset(dp, -1, sizeof(dp));
	tracking(N,L,I);
	return 0;
}