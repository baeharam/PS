#include <iostream>

int main(void)
{
	int t;
	int h, w, n;
	std::cin >> t;
	int *tlist = new int[t];
	int number = 0;

	for (int i = 0; i < t; i++){
		std::cin >> h; std::cin >> w; std::cin >> n;
		while (n-h>0){
			n -= h;
			number++;
		}
		number++;
		tlist[i] = n * 100 + number;
		number = 0;
	}

	for (int i = 0; i < t; i++) std::cout << tlist[i] << std::endl;

	delete[] tlist;
	return 0;
}