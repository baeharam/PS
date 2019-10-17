#include <iostream>

const int max = 10000 + 1;

int main(void)
{
	std::ios_base::sync_with_stdio(false);

	int tc,n; std::cin >> tc;

	while (tc--){
		std::cin >> n;
		int min = n-2, prime=0;
		// 에라토스테네스의 체
		bool eratos[max] = { false }; eratos[0] = true; eratos[1] = true;

		// 소수인것과 아닌것을 걸러내기
		for (int i = 2; i <= n; i++){
			if (eratos[i] == false)
				for (int j = i + i; j <= n; j += i) eratos[j] = true;
		}

		// 2부터 소수인 것들만 골라서 n과의 차이도 소수인것을 본다.
		// 그 중에 그 차이가 제일 작은 첫번째 소수를 prime에 담는다.
		for (int i = 2; i <= n; i++){
			if (!eratos[i] && !eratos[n - i]){
				if (n-i-i>=0 && min > n - i - i) {
					min = n - i - i;
					prime = i;
				}
			}
		}

		std::cout << prime << " " << n - prime << std::endl;
	}

	return 0;
}