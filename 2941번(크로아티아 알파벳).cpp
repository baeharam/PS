#include <iostream>

int main(void)
{
	char s[100 + 1];
	std::cin >> s;

	int cNum = 0;

	for (int i = 0; s[i];){
		switch (s[i]){
		case 'c':
			if (s[i + 1] == '='){ cNum++; i += 2; }
			else if (s[i + 1] == '-') { cNum++; i += 2; }
			else { cNum++; i++; }
			break;
		case 'd':
			if (s[i + 1] == 'z'){
				if (s[i + 2] == '=') {
					cNum++;
					i += 3;
				}
				else { cNum+=2; i+=2; }
			}
			else if (s[i + 1] == '-') { cNum++; i += 2; }
			else { cNum++; i++; }
			break;
		case 'l':
		case 'n':
			if (s[i + 1] == 'j') { cNum++; i += 2; }
			else { cNum++; i++; }
			break;
		case 's':
		case 'z':
			if (s[i + 1] == '=') { cNum++; i += 2; }
			else { cNum++; i++; }
			break;
		default:
			cNum++;
			i++;
		}
	}
	std::cout << cNum;
	return 0;
}