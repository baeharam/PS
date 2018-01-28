#include <iostream>
#include <stack>
#include <string>

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::string str; std::cin >> str;

	std::stack<char> s;

	// 곱해주는 변수와 최종값 변수
	int mul = 1, sum = 0; 

	for (int i = 0; i < str.length(); i++){
		if (str[i] == '('){
			mul *= 2; s.push(str[i]);
			if (str[i + 1] == ')') sum += mul;
		}
		else if (str[i] == '['){
			mul *= 3; s.push(str[i]);
			if (str[i + 1] == ']') sum += mul;
		}
		else if (!s.empty() && str[i] == ')'){
			if (s.top() == '(') mul /= 2, s.pop();
			else break;
		}
		else if (!s.empty() && str[i] == ']')
			if (s.top() == '[') mul /= 3, s.pop();
			else break;
	}

	std::cout << (s.empty() ? sum : 0) << '\n';

	return 0;
}
