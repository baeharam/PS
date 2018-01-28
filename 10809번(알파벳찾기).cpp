#include <iostream>
#include <string>

int main(void)
{
	std::string s;
	std::cin >> s;
	char a = 'a';
	
	for (int i = 0; i < 26; i++,a++){
		if (s.find(a) != std::string::npos)
			std::cout << s.find(a) << " ";
		else
			std::cout << -1 << " ";
	}
	return 0;
}