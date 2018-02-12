#include <iostream>
#include <algorithm>

int dp[500 + 1][500 + 1];
int novel[500 + 1];
int sum[500 + 1];

int main(void)
{
	int tc; std::cin >> tc;
	int chapter;

	while (tc--) {
		std::cin >> chapter;

		//std::cout << "original\n\n";

		// novel 배열에는 파일의 각 장이 가지는 크기를 넣고
		// sum 배열에는 그 파일크기들의 누적합을 계산해서 넣는다.
		for (int i = 1; i <= chapter; i++) {
			std::cin >> novel[i];
			sum[i] = sum[i - 1] + novel[i];
		}

		// 1번째 장부터 마지막 장인 chapter 바로 직전까지 반복한다.
		for (int i = 1; i < chapter; i++) {
			for (int x = 1; x + i <= chapter; x++) {
				//std::cout << x << "번째 장부터 " << x + i << "번째 장까지 : ";
				int y = x + i;
				dp[x][y] = INT_MAX;

				for (int k = x; k < y; k++) {
					//std::cout << x << " ~ " << k << " , " << k+1 << " ~ " << y<< " | ";
					dp[x][y] = std::min(dp[x][y], dp[x][k] + dp[k + 1][y] + sum[y] - sum[x - 1]);
				}
				std::cout << '\n';
			}
		}
		
		std::cout << dp[1][chapter];

	}

	return 0;
}