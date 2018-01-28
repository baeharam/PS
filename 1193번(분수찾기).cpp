#include <iostream>

int main(void)
{
	int x, i = 1;
	std::cin >> x;

	while ((i*i - i + 2) / 2 <= x)i++;
	i -= 1;

	int org = (i*i - i + 2) / 2;

	if (i % 2 == 0)
		std::cout << 1 + (x - org) << '/' << i - (x - org);
	else
		std::cout << i - (x - org) << '/' << 1 + (x - org);

	return 0;
}