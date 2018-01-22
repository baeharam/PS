#include <iostream>

// 메모이제이션
int memo[1000+1][1000+1]; // n과 k의 제한이 1000까지
const int mod = 10007;

int bino(int n, int k)
{
	if (memo[n][k] != 0) return memo[n][k];
	else if (n == k || k == 0) return memo[n][k] = 1;
	else if (k == 1) return memo[n][k] = n;
	else return memo[n][k]= (bino(n - 1, k - 1) + bino(n - 1, k))%mod;
}

int main(void)
{
	int n, k; std::cin >> n; std::cin >> k;
	std::cout << bino(n,k);

	return 0;
}