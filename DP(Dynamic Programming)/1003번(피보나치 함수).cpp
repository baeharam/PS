#include <cstdio>

// 0~40
int memo[41][2];

void fibonacci(int n) {
	// memo에 값이 업데이트 됬으면 그냥 리턴
	if (memo[n][0] != -1 && memo[n][1] != -1) return;
	// memo에 값이 업데이트 되지 않았고 이전 n-2, n-1의 값이 전부 업데이트 되었으면
	// 원래 피보나치 수열 계산방식으로 업데이트
	else if ((memo[n-2][0] != -1 && memo[n-2][1] != -1) &&
		(memo[n - 1][0] != -1 && memo[n - 1][0] != -1)) {
		memo[n][0] = memo[n - 2][0] + memo[n - 1][0];
		memo[n][1] = memo[n - 2][1] + memo[n - 1][1];
	}
	// memo[n]이 업데이트 안됬고 memo[n-2], memo[n-1]중 하나라도 업데이트 안되었으면 
	// 다시 피보나치 함수를 불러서 업데이트 시킨 후에 마지막에 n에 대해 다시 불러서 마무리한다.
	else {
		fibonacci(n - 1);
		fibonacci(n - 2);
		fibonacci(n);
	}
}

int main(void)
{
	int tc, n; scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		// 전부 -1로 초기화
		for (int i = 0; i <= 40; i++) {
			memo[i][0] = -1;
			memo[i][1] = -1;
		}
		// 0과 1에 대한 초기화
		memo[0][0] = 1, memo[1][1] = 1;
		memo[0][1] = 0, memo[1][0] = 0;
		fibonacci(n);
		printf("%d %d\n", memo[n][0], memo[n][1]);
	}
}