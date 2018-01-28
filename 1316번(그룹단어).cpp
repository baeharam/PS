#include <iostream>
#include <cstring>

int main(void)
{
	int n;
	char s[100 + 1];
	bool group_flag[26] = { false };
	bool answer_flag = true;
	int num=0;

	std::cin >> n;
	for (int i = 0; i < n; i++){
		std::cin >> s;
		for (int j = 0; j < strlen(s); j++){
			if (group_flag[s[j] - 'a'] == false)
				group_flag[s[j] - 'a'] = true;
			else{
				if (s[j] != s[j - 1]){
					answer_flag = false;
					break;
				}
			}
		}
		if (answer_flag) num++;
		for (int i = 0; i < 26; i++) group_flag[i] = false;
		answer_flag = true;
	}

	std::cout << num;

	return 0;
}