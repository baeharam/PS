#include <cstdio>
#include <algorithm>
#include <cstring>

// dp[턴][왼쪽끝][오른쪽끝]
// 근우의 턴에는 최대로 하도록 점수계산
// 명우의 턴에는 최소로 하도록 점수계산
int dp[2][1001][1001];
int card[1001];

int game(int turn, int left, int right)
{
	// 카드가 1개인 경우 근우는 점수를 얻고 명우는 그냥 넘긴다.
	if (left == right) {
		if (turn == 0) return card[left];
		else if (turn == 1) return 0;
	}

	if (dp[turn][left][right] != -1) return dp[turn][left][right];

	// 근우의 경우 왼쪽 카드를 선택한 경우와 오른쪽 카드를 선택한 경우 중 최댓값을 재귀적으로 계산한다.
	if (turn == 0)
		dp[turn][left][right] = std::max(card[left] + game(1, left + 1, right), card[right] + game(1, left, right - 1));
	// 명우의 경우 근우의 점수를 최소로 하는 값을 찾기 위해 재귀적으로 계산한다. 단, 명우는 점수를 얻지 않으므로 카드점수는 더하지 않는다.
	else if(turn==1)
		dp[turn][left][right] = std::min(game(0, left + 1, right), game(0, left, right - 1));
	
	return dp[turn][left][right];
}

int main(void)
{
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n; scanf("%d", &n);
		memset(dp, -1, sizeof(dp));
		for (int i = 1; i <= n; i++) scanf("%d", &card[i]);

		printf("%d\n", game(0,1,n));
	}
	return 0;
}