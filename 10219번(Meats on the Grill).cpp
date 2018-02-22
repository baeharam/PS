#include <iostream>

char grill[12][12];
int h, w;

int main(void)
{
	int tc; std::cin >> tc;

	while (tc--) {
		std::cin >> h >> w;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++)
				std::cin >> grill[i][j];
		}

		for (int i = 1; i <= h; i++) {
			for (int j = w; j >= 1; j--)
				std::cout << grill[i][j];
			std::cout << '\n';
		}
	}
	return 0;
}