#include <iostream>

typedef unsigned long long ull;

ull gcd(ull a, ull b)
{
	if (b == 0) return a;
	else gcd(b, a%b);
}

int main(void)
{
	ull a, b; std::cin >> a >> b;
	if (a < b) std::swap(a, b);
	
	int n = gcd(a, b);

	while (n--) std::cout << '1';
	return 0;
}