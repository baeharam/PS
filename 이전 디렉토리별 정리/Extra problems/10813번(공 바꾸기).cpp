#include <iostream>

int main(void)
{
	int n, m; std::cin >> n >> m;
	int i, j;

	int *bagooni = new int[n + 1];
	for (int i = 1; i <= n; i++) bagooni[i] = i;

	while (m--){
		std::cin >> i >> j;
		std::swap(bagooni[i], bagooni[j]);
	}

	for (int i = 1; i <= n; i++) std::cout << bagooni[i] << ' ';

	delete[] bagooni;

	return 0;
}