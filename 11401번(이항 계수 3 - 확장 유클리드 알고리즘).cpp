#include <iostream>

const long long m = 1000000007LL; 
long long x = 0LL, y = 0LL;

void EGCD(long long a, long long b)
{
	
	// x,y의 초기값은 1과 0
	// b가 0에 도달했을 때, 즉 유클리드 알고리즘이 모두 진행됬을 때 돌아간다.
	if (b == 0){
		x = 1;
		y = 0;
		return;
	}

	EGCD(b, a%b); // 유클리드 알고리즘 진행

	long long temp = 0LL;
	temp = x;
	x = y;
	y = temp - (a / b)*y;
}

long long bino(long long n, long long k)
{
	long long nf=1LL;
	long long p=1LL;
	long long ans = 0LL;

	// n! 하면서 모듈러 연산
	for (long long i= n; i >= 1LL; i--){
		nf *= i;
		nf %= m;
	}
	// k! 하면서 모듈러 연산
	for (long long i = k; i >= 1LL; i--){
		p *= i;
		p %= m;
	}
	// (n-k)! 하면서 모듈러 연산
	for (long long i = n-k; i >= 1LL; i--){
		p *= i;
		p %= m;
	}
	// p는 모듈러연산이 적용된 k!(n-k)!

	// 확장 유클리드 알고리즘을 이용해 p의 역원을 구한다.
	EGCD(p, m);
	

	// 모듈러 연산의 분배법칙에 따라 다시 한 번 모듈러 연산을 해준다.
	ans = (nf*x) % m;
	return ans >= 0 ? ans : ans + m;
}


int main(void)
{
	long long n, k; std::cin >> n>>k;
	std::cout << bino(n, k);
	return 0;
}