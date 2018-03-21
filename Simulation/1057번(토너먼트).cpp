#include <iostream>

int main(void)
{
	int n, jimin, hansoo;
	std::cin >> n >> jimin >> hansoo;

	int round = 1;
	jimin % 2 == 0 ? jimin /= 2 : jimin = jimin / 2 + 1;
	hansoo % 2 == 0 ? hansoo /= 2 : hansoo = hansoo / 2 + 1;

	while (jimin!=hansoo) {
		round++;
		jimin % 2 == 0 ? jimin /= 2 : jimin = jimin / 2 + 1;
		hansoo % 2 == 0 ? hansoo /= 2 : hansoo = hansoo / 2 + 1;
	}

	std::cout << round;
	return 0;
}