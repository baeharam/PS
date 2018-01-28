#include <iostream>

int livenum(int k, int n)
{
	if (k == 0) return n;

	int sum = 0;

	for (int i = 1; i <=n; i++)
		sum += livenum(k - 1, i);
	return sum;
}

int main(void)
{
	int t;
	std::cin >> t;
	int *tList = new int[t];

	int k, n;
	for (int i = 0; i < t; i++){
		std::cin >> k;
		std::cin >> n;
		tList[i] = livenum(k, n);
	}


	for (int i = 0; i < t; i++)
		std::cout << tList[i] << std::endl;

	return 0;
}