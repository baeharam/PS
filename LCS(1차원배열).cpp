#include <iostream>
#include <string>

std::string curr[1001];
std::string prev[1001];

void LCS(std::string s1, std::string s2)
{
	for (int i = 0; i <= s1.size(); i++) {
		for (int j = 0; j <= s2.size(); j++) {
			if (i == 0 || j == 0) curr[j] = "";
			else {
				if (s1[i-1] == s2[j-1]) {
					curr[j].append(prev[j - 1]);
					curr[j].push_back(s1[i-1]);
				}
				else if (curr[j - 1].size() > prev[j].size()) curr[j] = curr[j - 1];
				else curr[j] = prev[j];
			}
		}
		// curr배열의 값들을 prev배열로 옮겨서 백업
		// 그 후 curr배열에서 계산한 값들 지워주기
		for (int j = 0; j < s2.size(); j++) {
			prev[j] = curr[j];
			curr[j] = "";
		}
	}
}

int main(void)
{
	std::string s2("ACAYKP");
	std::string s1("CAPCAK");

	LCS(s1, s2);

	std::cout << curr[s1.size()];

	return 0;
}