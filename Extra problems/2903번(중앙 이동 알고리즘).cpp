#include <iostream>
#include <cmath>

typedef long long ll;

int main(void)
{
	ll n; std::cin >> n;
	ll res = std::pow((std::pow(2.0, n) + 1), 2.0);
	std::cout << res;
	return 0;
}