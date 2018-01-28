#include <iostream>

int main(void)
{
	int m, n; std::cin >> m; std::cin >> n;
	int prime_sum=0, prime_min = 0;
	bool IsPrime = true, IsFirst = true;

	for (int i = m; i <= n; i++){
		if (i == 1) continue;
		for (int j = 2; j < i; j++){
			if (i%j == 0){ IsPrime = false; break; }
			else{ IsPrime = true; continue; }
		}
		if (IsPrime){
			prime_sum += i;
			if (IsFirst){ IsFirst = false; prime_min = i; }
		}
	}

	if (prime_sum == 0) std::cout << -1;
	else{
		std::cout << prime_sum << std::endl;
		std::cout << prime_min << std::endl;
	}

	return 0;
}