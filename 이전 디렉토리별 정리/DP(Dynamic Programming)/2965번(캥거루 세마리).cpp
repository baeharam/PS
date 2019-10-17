#include <iostream>
#include <algorithm>

int Jump(int A, int B, int C)
{
	int jump = 0;

	while (std::abs(B-C)>1 || std::abs(A-B)>1) {
		if (std::abs(B - C) > std::abs(A - B)) {
			A = B;
			B = B + 1;
			jump++;
		}
		else {
			C = B;
			B = B - 1;
			jump++;
		}
	}
	return jump;
}

/*int Jump(int A, int B, int C)
{
	int jump_ab = 0, jump_bc = 0;
	if (std::abs(A - B) > 1) {
		jump_ab = Jump(A, A + 1, B) + 1;
	}
	if (std::abs(B - C) > 1) {
		jump_bc = Jump(B, B + 1, C) + 1;
	}
	else if (std::abs(B - C) <= 1 && std::abs(A - B) <= 1) return 0;

	return jump_ab > jump_bc ? jump_ab : jump_bc;
}*/

int main(void)
{
	int a, b, c;

	std::cin >> a >> b >> c;
	std::cout << Jump(a, b, c);

	
	return 0;
}