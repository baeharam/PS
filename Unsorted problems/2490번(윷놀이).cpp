#include <iostream>

int main(void)
{
	int front = 0;
	int stick;

	for (int i = 0; i < 3; i++) {
		for (int i = 0; i < 4; i++) {
			std::cin >> stick;
			if (!stick) front++;
		}
		if (front == 0) std::cout << "E\n";
		else if (front == 1) std::cout << "A\n";
		else if (front == 2) std::cout << "B\n";
		else if (front == 3)std::cout << "C\n";
		else if (front == 4)std::cout << "D\n";
		front = 0;
	}

	return 0;
}