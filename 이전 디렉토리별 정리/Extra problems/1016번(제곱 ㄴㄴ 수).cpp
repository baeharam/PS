#include <cstdio>
#include <cmath>
#include <vector>

typedef long long ll;
const ll primeMax = 1000000;
int prime[primeMax + 1];
ll prime_square[primeMax];
bool isDivide[primeMax + 1];

/*
1~n까지의 숫자 중 에라토스테네스의 체를 써서 소수를 걸러낼 때
n까지의 배수가 아닌 루트n까지의 배수만 해도 되는 이유는?
n=ab라고 했을 때, a,b 모두가 루트n보다 크다면 ab가 n보다 커지게 되므로 반드시
적어도 1개는 루트n보다 작다. 따라서 루트n까지만 확인해도 1~n사이의 모든 소수가 걸러진다.
*/

void Eratos()
{
	// 1조가 최댓값이지만 루트1조인 100만까지만 걸러내도 됨.
	// 2부터 100만까지 prime배열에 초기화
	for (int i = 2; i <= primeMax; i++) prime[i] = i;

	// 에라토스테네스의 체, 2부터 시작해서 100만까지의 배수를 -1로 초기화
	// 즉, 2~100만 사이의 소수를 걸러내는 작업
	for (int i = 2; i <= primeMax; i++) {
		for (int j = 2; j <= primeMax / i; j++)
			prime[i*j] = -1;
	}

	// 걸러낸 소수를 제곱하여 prime_square 배열에 저장
	for (int i = 2, j = 0; i <= primeMax; i++) {
		if (prime[i] != -1)
			prime_square[j++] = (ll)prime[i] * prime[i];
	}
}

int main(void)
{
	ll min, max; scanf("%lld %lld", &min, &max);
	Eratos();
	// 0부터 max까지 isDivide배열의 값을 false로 초기화
	for (ll i = min; i <= max; i++) isDivide[i - min] = false;

	int ans = 0, i = 0;


	while (prime_square[i] && prime_square[i]<=max) {
		ll j = ((min + prime_square[i] - 1) / prime_square[i]) *prime_square[i];
		while (j <= max) {
			isDivide[j - min] = true;
			j += prime_square[i];
		}
		i++;
	}

	for (ll i = min; i <= max; i++) if (isDivide[i-min]) ans++;

	printf("%lld", (max-min+1)-ans);
	return 0;
}