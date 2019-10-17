#include <iostream>

int dp[500 + 1][500 + 1];
int novel[500 + 1];
int C[500 + 1];
int A[500 + 1][500 + 1];

int main(void)
{
	int tc; std::cin >> tc;
	int last_chapter;

	while (tc--) {
		std::cin >> last_chapter;

		std::cout << "knuth optimization\n\n";

		// novel 배열에는 파일의 각 장이 가지는 크기를 넣고
		// C 배열에는 그 파일크기들의 누적합을 계산해서 넣는다.
		for (int i = 1; i <= last_chapter; i++) {
			std::cin >> novel[i];
			C[i] = C[i - 1] + novel[i];
		}
		for (int i = 1; i <= last_chapter; i++)
			A[i - 1][i] = i;

		// 1번째 장부터 마지막 장인 last_chapter 바로 직전까지 반복한다.
		for (int i = 2; i <= last_chapter; i++) {
			for (int x = 0; x + i <= last_chapter; x++) {
				std::cout << x + 1 << "번째 장부터 " << x + i << "번째 장까지 : ";
				int y = x + i;
				dp[x][y] = INT_MAX;

				for (int k = A[x][y-1]; k <=A[x+1][y]; k++) {
					std::cout << x+1 << " ~ " << k << " , " << k << " ~ " << y << " | ";
					int min = dp[x][k] + dp[k][y] + C[y] - C[x];
					if (dp[x][y] > min) {
						dp[x][y] = min;
						A[x][y] = k;
					}
				}
				std::cout << '\n';
			}
		}

		std::cout << dp[0][last_chapter];

	}

	return 0;
}