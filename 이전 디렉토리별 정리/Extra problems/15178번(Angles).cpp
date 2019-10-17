#include <iostream>

int main(void)
{
	int n,a,b,c; std::cin >> n;
	while (n--) {
		std::cin >> a >> b >> c;
		if (a + b + c != 180) std::cout << a << ' ' << b << ' ' << c << ' ' << "Check\n";
		else std::cout << a << ' ' << b << ' ' << c << ' ' << "Seems OK\n";
	}
	return 0;
}