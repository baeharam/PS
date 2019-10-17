#include <iostream>

int device[1001];

int main(void)
{
	int tc; std::cin >> tc;
	int n, a, b;
	char alpha;

	while (tc--) {
		std::cin >> n;
		while (n--) {
			std::cin >> alpha >> a >> b;
			for (int i = a; i <= b - 1; i++) device[i]++;
		}
		for (int i = 0; i <= 1000; i++) {
			if (device[i] != 0) {
				std::cout << static_cast<char>('A' + device[i] - 1);
			}
		}
		std::cout << '\n';
		for (int i = 0; i <= 1000; i++) device[i] = 0;
	}
	return 0;
}