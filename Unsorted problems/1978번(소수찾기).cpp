#include <iostream>

int main(void)
{
	int n,prime=0,prime_num=0; std::cin >> n;
	bool IsPrime = true;
	while (n--){
		std::cin >> prime;
		if (prime == 1) continue;
		for (int i = 2; i < prime; i++){
			if (prime%i == 0) { IsPrime = false; break; }
			else { IsPrime = true; continue; }
		}
		if (IsPrime) prime_num++;
	}

	std::cout << prime_num << std::endl;
	return 0;
}