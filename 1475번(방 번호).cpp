#include <iostream>
#include <string>

int main(void)
{
	std::string n;
	std::cin >> n;
	int numList[9] = { 0 };

	for (int i = 0; i < n.length(); i++){
		if (n[i] == '6' || n[i] == '9') numList[6]++;
		else numList[n[i] - '0']++;
	}
	if (numList[6] % 2 == 0) numList[6] /= 2;
	else if (numList[6] % 2 != 0) numList[6] = numList[6] / 2 + 1;
	
	int max = numList[0];
	for (int i = 1; i < 9; i++)
		if (max < numList[i]) max = numList[i];

	std::cout << max;

	return 0;
}