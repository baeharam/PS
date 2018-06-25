#include <iostream>
#include <string>
using namespace std;
char pan[9][9];

int main(void)
{
	string s;
	int horse = 0;
	for (int i = 1; i <= 8; i++) {
		cin >> s;
		for (int j = 0; j < 8; j++) {
			pan[i][j + 1] = s[j];
			if (pan[i][j+1] == 'F') {
				if (i % 2 != 0 && (j+1) % 2 != 0) horse++;
				else if (i % 2 == 0 && (j+1) % 2 == 0) horse++;
			}
		}
	}
	cout << horse;
	return 0;
}