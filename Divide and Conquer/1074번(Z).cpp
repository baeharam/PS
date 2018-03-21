#include <iostream>
#include <cmath>

int order[2][2];
int ans;

void matrixZ(int rb, int cb, int size, int r, int c)
{
	if (size <= 2) {
		order[0][0] = order[1][1] ? order[1][1] + 1 : order[1][1];
		if (rb == r && cb == c) ans = order[0][0];
		order[0][1] = order[0][0] + 1;
		if (rb == r && cb + 1 == c) ans = order[0][1];
		order[1][0] = order[0][1] + 1;
		if (rb + 1 == r && cb == c) ans = order[1][0];
		order[1][1] = order[1][0] + 1;
		if (rb + 1 == r && cb + 1 == c) ans = order[1][1];
	}
	else {
		matrixZ(rb, cb, size / 2, r, c);
		matrixZ(rb, cb + size / 2, size / 2, r, c);
		matrixZ(rb + size / 2, cb, size / 2, r, c);
		matrixZ(rb + size / 2, cb + size / 2, size / 2, r, c);
	}
}

int main(void)
{
	int n, r, c; std::cin >> n >> r >> c;
	matrixZ(0, 0, (int)std::pow(2.0, n), r, c);
	std::cout << ans;
	return 0;
}