#include <iostream>
#include <string>

int dp[1000][1000];

void LCS(std::string s1, std::string s2)
{
	for (int i = 0; i < s1.size(); i++) {
		for (int j = 0; j < s2.size(); j++) {
			if (s1[i] == s2[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else {
				if (dp[i + 1 - 1][j + 1] > dp[i + 1][j + 1 - 1])
					dp[i + 1][j + 1] = dp[i + 1 - 1][j + 1];
				else
					dp[i + 1][j + 1] = dp[i + 1][j + 1 - 1];
			}
		}
	}
}

int main(void)
{
	std::string s1;
	std::string s2;

	std::cin >> s1 >> s2;


	LCS(s1, s2);

	std::cout << dp[s1.size()][s2.size()];

	return 0;

}