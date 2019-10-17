#include <iostream>

int main(void)
{
	int x1, y1, x2, y2, x3, y3;
	std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	int S = ((x2 - x1)*(y3 - y1) - (y2 - y1)*(x3 - x1)) / 2;
	if (S > 0) std::cout << "1";
	else if (S < 0) std::cout << "-1";
	else std::cout << "0";
	return 0;
}