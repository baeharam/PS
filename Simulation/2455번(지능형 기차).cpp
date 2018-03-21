#include <iostream>

int main(void)
{
	int people = 0, max = 0;
	int ascend, descend;

	for (int i = 0; i < 4; i++) {
		std::cin >> descend >> ascend;
		people += (ascend - descend);
		if (max < people) max = people;
	}
	std::cout << max;
	return 0;
}