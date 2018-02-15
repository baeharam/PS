#include <iostream>
#include <algorithm>
#include <functional>
#include <cmath>
#include <vector>

int gcd(int a, int b)
{
	while (b) {
		int temp = a;
		a = b;
		b = temp % b;
	}
	return a;
}

int main(void)
{
	int n; std::cin >> n;
	int num[100];

	for (int i = 0; i < n; i++) std::cin >> num[i];

	std::sort(num, num + n, std::greater<int>());

	for (int i = 0; i < n - 1; i++) num[i] -= num[i + 1];

	int gcdNum = num[0];

	for (int i = 1; i < n - 1; i++) {
		gcdNum = gcd(gcdNum, num[i]);
	}

	std::vector<int> divisor;

	for (int i = 2; i <= std::sqrt(gcdNum); i++) {
		if (gcdNum%i == 0) {
			divisor.push_back(i);
			if (i != gcdNum / i) divisor.push_back(gcdNum / i);
		}
	}
	divisor.push_back(gcdNum);

	std::sort(divisor.begin(), divisor.end());

	
	for (int i = 0; i < divisor.size(); i++) std::cout << divisor[i] << ' ';

	return 0;
}