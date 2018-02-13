#include <iostream>

typedef unsigned long long ull;

ull gcd(ull a, ull b)
{
	ull gcdNum = 0;
	for (ull i = b; i >= 1; i--) {
		if (a%i == 0 && b%i == 0) {
			gcdNum = i;
			break;
		}
	}
	return gcdNum;
}

int main(void)
{
	ull a, b; std::cin >> a >> b;
	if (a < b) std::swap(a, b);
	std::cout << a*b/gcd(a, b);

	return 0;
}