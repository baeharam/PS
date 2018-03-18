#include <iostream>

int square(int n)
{
	return n*n;
}

int main(void)
{
	int n, i=1;
	std::cin >> n;
	
	while ((3 * square(i) - 3 * i + 1) < n) i++;

	std::cout << i;
	return 0;
}