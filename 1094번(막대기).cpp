#include <iostream>
#include <vector>

int main(void)
{
	int stick = 64, sum = 64;
	int x; std::cin >> x;
	std::vector<int> sticks;
	sticks.push_back(stick);

	while (sum > x) {
		sticks.pop_back();
		sticks.push_back(stick / 2);
		sum = 0;
		for (int i = 0; i < sticks.size(); i++) sum += sticks[i];
		if (sum < x) {
			sticks.push_back(stick / 2);
			sum += stick / 2;
		}

		stick /= 2;
	}
	std::cout << sticks.size();
	return 0;
}