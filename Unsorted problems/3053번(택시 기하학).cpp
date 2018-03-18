#include <iostream>
#include <cmath>

const double pi = 3.14159265358979323846;

int main(void)
{
	int r; std::cin >> r;

	std::cout.setf(std::ios::fixed);
	std::cout.setf(std::ios::showpoint);
	std::cout.precision(6);
	std::cout << pi * r*r << '\n';
	std::cout << 2.0 * r*r;
	return 0;
}