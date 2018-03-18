#include <iostream>
#include <string>

int dp[1001][1001];

void LCS_length(std::string s1, std::string s2)
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

 std::string LCS_backtracking(std::string s1, std::string s2, int i, int j)
{
	 if (i == 0 || j == 0) return "";
	 else {
		 if (s1[i-1] == s2[j-1]) {
			 std::string temp = LCS_backtracking(s1, s2, i - 1, j - 1);
			 temp.push_back(s1[i-1]);
			 return temp;
		 }
		 else if (dp[i - 1][j] > dp[i][j - 1]) return LCS_backtracking(s1, s2, i - 1, j);
		 else return LCS_backtracking(s1, s2, i, j - 1);
	 }
}

int main(void)
{
	std::string s1;
	std::string s2;

	std::cin >> s1 >> s2;

	LCS_length(s1, s2);

	std::cout << dp[s1.size()][s2.size()] << '\n' << LCS_backtracking(s1, s2, s1.size(), s2.size());
	return 0;
}