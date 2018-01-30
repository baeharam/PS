#include <iostream>
#include <algorithm>

// 배열을 활용할 때는 숫자삼각형의 행과 열 자체를 인덱스로 삼기 때문에
// 최대입력값인 500보다 1개 더 많아야 한다.
int dp[500 + 1][500 + 1]; // 입력값을 담을 숫자삼각형
int ans[500 + 1][500 + 1]; // 누적합을 담을 숫자삼각형


int main(void)
{
	int n; std::cin >> n;
	
	// 입력
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= i; j++)
			std::cin >> dp[i][j];
	}

	// 누적합을 담을 새로운 숫자삼각형 배열 ans를 이용한다.
	// 숫자삼각형은 총 n개의 행으로 이루어져있으므로 그만큼 반복한다.
	for (int i = 1; i <= n; i++){
		// 각 행에는 i개에 해당하는 숫자가 있기 때문에 그만큼 누적합을 시킨다.
		for (int j = 1; j <= i; j++){
			// 1열일 경우 왼쪽 대각선으로 내려오는 경우
			if (j == 1) ans[i][j] = ans[i - 1][j] + dp[i][j];
			// i열일 경우 오른쪽 대각선으로 내려오는 경우
			else if (j == i) ans[i][j] = ans[i - 1][j - 1] + dp[i][j];
			// 1,i열이 아닐 경우 중간에 있는 경우인데 이 문제의 특성에 따라서
			// 왼쪽 위나 오른쪽 위에서 값을 받을 수 있다.
			// 최댓값을 구하기 때문에 두 값 중 더 큰 값을 계산해서 누적시킨다.
			else{
				int temp = std::max(ans[i - 1][j - 1], ans[i - 1][j]);
				ans[i][j] = temp + dp[i][j];
			}
		}
	}

	// 누적합 배열의 n번째 행의 값 중 최댓값을 구해내면 됨.
	int maxValue = 0;
	for (int i = 1; i <= n; i++){
		if (maxValue < ans[n][i])
			maxValue = ans[n][i];
	}

	std::cout << maxValue;

	return 0;
}