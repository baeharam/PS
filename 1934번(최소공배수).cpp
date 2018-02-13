#include <iostream>

int gcd(int a, int b)
{
	if (b == 0) return a;
	else gcd(b, a%b);
}

int main(void)
{
	int tc; std::cin >> tc;
	while (tc--) {
		int a, b;
		std::cin >> a >> b;
		if (a < b) std::swap(a, b);
		std::cout << a * b/gcd(a, b) << '\n';
	}
	return 0;
}