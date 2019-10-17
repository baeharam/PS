#include <cstdio>
#include <cmath>

int main(void)
{
	int n, k = 1; scanf("%d", &n);
	bool prime = true;
	int root_n = (int)sqrt(n);

	// 소수를 판별할 때는 제곱근까지만 나눠보면 알 수있다.
	// 왜? n을 소수가 아니라고 하면 n=a*b인데 a,b 중 작은값의 최댓값은 루트n이기 때문에.
	for (int i = 2; i <= root_n; i++) {
		if (n%i == 0) {
			k = i;
			prime = false;
			break;
		}
	}

	if (prime) printf("%d", n - 1);
	else printf("%d", n - n / k);


	return 0;
}