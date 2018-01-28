#include <iostream>

int main(void)
{
	int a, b;
	std::cin >> a; std::cin >> b;
	a = (a % 10) * 100 + (a % 100) / 10 * 10 + (a / 100);
	b = (b % 10) * 100 + (b % 100) / 10 * 10 + (b / 100);

	std::cout << (a > b ? a : b);

	return 0;
}