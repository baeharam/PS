#include <iostream>

int main(void)
{
	int n; std::cin >> n;
	int r = 1;
	for (int i = 2; i <= n; i++){
		r *= i;
	}
	std::cout << r;
	return 0;
}