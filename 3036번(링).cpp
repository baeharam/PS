#include <iostream>

int gcd(int a, int b)
{
	if (b == 0) return a;
	else gcd(b, a%b);
}

int main(void)
{
	int n; std::cin >> n;
	int num[100];
	for (int i = 0; i < n; i++) std::cin >> num[i];

	for (int i = 1; i < n; i++) {
		int divisor = gcd(num[0], num[i]);
		std::cout << num[0] / divisor << '/' << num[i] / divisor << '\n';
	}

	return 0;
}