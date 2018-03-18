#include <iostream>
#include <string>

int main(void)
{
	int v; std::cin >> v;
	std::string vote; std::cin >> vote;

	int a = 0, b = 0;
	for (int i = 0; i < vote.size(); i++)
		vote[i] == 'A' ? a++ : b++;

	if (a>b) std::cout << 'A';
	else if (a < b) std::cout << 'B';
	else std::cout << "Tie";

	return 0;
}