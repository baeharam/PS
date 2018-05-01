#include <cstdio>
#include <algorithm>
#include <cstring>

int dp[10005]; // 1원~10,000원까지 가질 수 있음
int candy[5005][2]; // 사탕의 개수는 최대 5000개 그리고 사탕의 칼로리와 가격

int main(void)
{
	// int_m, int_p는 소수를 정수로 바꾸기 위한 변수
	int n, c, int_m, int_p;
	double m, p;
	scanf("%d %lf", &n, &m);
	int_m = (int)(m * 100 + 0.5);

	while (n&&int_m) {
		for (int i = 1; i <= n; i++) {
			scanf("%d %lf", &c, &p);
			int_p = (int)(p * 100 + 0.5);
			candy[i][0] = c; candy[i][1] = int_p;
		}

		for (int p = 1; p <= int_m; p++) {
			for (int i = 1; i <= n; i++) {
				int ci = candy[i][0]; // 사탕의 칼로리
				int pi = candy[i][1]; // 사탕의 가격
				if (pi <= p)
					dp[p] = std::max(dp[p], ci + dp[p - pi]);
			}
		}

		printf("%d\n", dp[int_m]);
		memset(dp, 0, sizeof(dp));
		scanf("%d %lf", &n, &m);
		int_m = (int)(m * 100 +0.5);
	}

	return 0;
}