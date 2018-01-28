#include <algorithm>
#include <iostream>
#include <string>

int main(void)
{
	std::string n;
	std::cin >> n;

	int len = n.length();

	int *List = new int[len];

	for (int i = 0; i < len; i++)
		List[i] = n[i] - '0';

	std::sort(List, List + len);

	for (int i = len - 1; i >= 0; i--)
		std::cout << List[i];

	delete[] List;

	return 0;
}