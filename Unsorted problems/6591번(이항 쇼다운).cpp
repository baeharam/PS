#include <iostream>

typedef unsigned long long ull;
ull memo[3000][3000]; // 메모이제이션

ull Comb(ull n, ull m)
{
	if (n == m || m == 0) return memo[n][m] = 1;
	else if (m == 1) return memo[n][m] = n;
	else if (memo[n][m] != 0) return memo[n][m];
	else return memo[n][m] = Comb(n - 1, m - 1) + Comb(n - 1, m);
}

int main(void)
{
	memo[1][0] = memo[1][1] = 1; // 1C0=1C1=1로 초기화
	ull n, m; std::cin >> n >> m;
	ull combination;

	while (n || m){
		if (m >= n / 2) m = n - m;
		if (n == m || m == 0) combination = 1;
		else if (m == 1) combination = n;
		else if (m == 2) combination = (n*(n - 1)) / 2;
		else combination=Comb(n, m);
		std::cout << combination<<'\n';
		std::cin >> n >> m;
	}

	return 0;
}