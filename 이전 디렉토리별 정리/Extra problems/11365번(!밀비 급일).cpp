#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	vector<string> lock;
	string s = ""; getline(cin, s);

	while (s.compare("END")) {
		lock.push_back(s);
		getline(cin,s);
	}

	for (int i = 0; i < lock.size(); i++) {
		for (int j = lock[i].size() - 1; j >= 0; j--)
			std::cout << lock[i][j];
		std::cout << '\n';
	}
	return 0;
}
