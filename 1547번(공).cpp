#include <iostream>

bool cups[4];

int main(void)
{
	int m, x, y; std::cin >> m;
	cups[1] = true;

	while (m--) {
		std::cin >> x >> y;
		std::swap(cups[x], cups[y]);
	}
	for (int i = 1; i <= 3; i++) if (cups[i] == true) std::cout << i;
	return 0;
}