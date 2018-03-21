#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> LCS_table[1000 + 1][1000 + 1];

void LCS_topdown(std::string x, std::string y)
{
	// LCS 테이블의 빈 수열과 비교하는 부분을 모두 빈 수열로 만든다.
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++)
			if(i==0 || j==0)
				LCS_table[i][j].push_back("");
	}

	for (int i = 0; i < x.size(); i++) {
		for (int j = 0; j < y.size(); j++) {
			// 문자열 x,y의 인덱스는 무조건 0부터 시작이지만 
			// LCS 테이블은 1,1의 인덱스부터 시작이기 때문에 LCS_table을 참조할 때는 기존 i,j에 1을 더해주어야 한다.

			// 1. 같은 원소일 경우
			// 이전 LCS에 현재 접두사를 붙여주는 것이다. 그러나 여러개 있을 수도 있으므로 모두 고려한다.
			if (x[i] == y[j]) {
				std::cout << i + 1 << "행 " << j + 1 << "열의 수열은 ";
				for (int k = 0; k < LCS_table[i + 1 - 1][j + 1 - 1].size(); k++) {
					std::string temp("");
					temp.append(LCS_table[i + 1 - 1][j + 1 - 1][k]);
					temp.push_back(x[i]);
					LCS_table[i + 1][j + 1].push_back(temp);
					std::cout << temp << ", ";
				}
				std::cout << "입니다.\n";
			}

			// 2. 다른 원소인 경우
			else {
				// LCS[i-1][j]>LCS[i][j-1] 인 경우
				// 그 값들을 전부 가져와 LCS[i][j]에 넣는다.
				// 길이를 비교할 때 처음 접두사의 길이만 비교하는데 이는 LCS 테이블의 한 인덱스에는 같은 길이의 접두사만 들어갈 수 밖에
				// 없기 때문이다. 이건 LCS가 뭔지 알고있으면 당연한 것이다.
				if (LCS_table[i + 1 - 1][j + 1][0].size() > LCS_table[i + 1][j + 1 - 1][0].size()) {
					std::cout << i + 1 << "행 " << j + 1 << "열의 수열은 ";
					for (int k = 0; k < LCS_table[i + 1 - 1][j + 1].size(); k++) {
						LCS_table[i + 1][j + 1].push_back(LCS_table[i + 1 - 1][j + 1][k]);
						std::cout << LCS_table[i + 1 - 1][j + 1][k] << ", ";
					}
					std::cout << "입니다.\n";
				}
				// LCS[i-1][j]<LCS[i][j-1] 인 경우
				// 그 값들을 전부 가져와 LCS[i][j[에 넣는다.
				else if (LCS_table[i + 1 - 1][j + 1][0].size() < LCS_table[i + 1][j + 1 - 1][0].size()) {
					std::cout << i + 1 << "행 " << j + 1 << "열의 수열은 ";
					for (int k = 0; k < LCS_table[i + 1][j + 1 - 1].size(); k++) {
						LCS_table[i + 1][j + 1].push_back(LCS_table[i + 1][j + 1 - 1][k]);
						std::cout << LCS_table[i + 1][j + 1 - 1][k] << ", ";
					}
					std::cout << "입니다.\n";
				}
				// LCS[i-1][j]==LCS[i][j-1]인 경우
				// 두 인덱스의 값들을 모두 넣는데, 같은 원소는 중복하지 않고 한번만 넣는다.
				else {
					std::cout << i + 1 << "행 " << j + 1 << "열의 수열은 ";
					for (int k = 0; k < LCS_table[i + 1 - 1][j + 1].size(); k++) {
						LCS_table[i + 1][j + 1].push_back(LCS_table[i + 1 - 1][j + 1][k]);
						std::cout << LCS_table[i+1-1][j+1][k] << ", ";
					}
					// 위에서 넣은 값중에 중복있으면 빼는 경우
					for (int k = 0; k < LCS_table[i + 1][j + 1 - 1].size(); k++) {
						bool find = false;
						for (int h = 0; h < LCS_table[i + 1][j + 1].size(); h++) 
							if (!LCS_table[i + 1][j + 1 - 1][k].compare(LCS_table[i + 1][j + 1][h])) {
								find = true; break;
							}
						if (!find) {
							LCS_table[i + 1][j + 1].push_back(LCS_table[i + 1][j + 1 - 1][k]);
							std::cout << LCS_table[i + 1][j + 1 - 1][k] << ", ";
						}
					}
					std::cout << "입니다.\n";
				}
			}
		}
	}
}

int main(void)
{
	std::string s1;
	std::string s2;

	std::cin >> s1 >> s2;

	std::cout << "다음은 LCS테이블의 값들을 나타낸 것입니다...\n\n";

	LCS_topdown(s1, s2);

	std::cout << "\n따라서 LCS(" << s1 << ", " << s2 << ")은 ";
	for (int i = 0; i < LCS_table[s1.size()][s2.size()].size(); i++) std::cout << LCS_table[s1.size()][s2.size()][i] << ' ';
	std::cout << "입니다.\n";
		

	return 0;

}