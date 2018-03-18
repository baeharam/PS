#include <iostream>
#include <cctype>

int main(void)
{
	char s[1000000 + 1];
	int alpha[26] = { 0 };
	std::cin >> s;

	for (int i = 0; s[i]; i++){
		if (isupper(s[i])) alpha[s[i] - 'A']++;
		else alpha[s[i] - 'a']++;
	}

	int max = alpha[0];
	char answer = 'A';
	bool flag = false;

	for (int i = 1; i < 26; i++){
		if (max < alpha[i]){
			max = alpha[i];
			answer = i+'A';
			flag = false;
		}
		else if (max == alpha[i]) flag = true;
	}
	
	if (flag) std::cout << "?";
	else std::cout << answer;

	return 0;

}