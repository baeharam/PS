#include <iostream>

typedef long long ll;
const ll p = 1000000007;

ll dqs(ll x, ll y)
{
	ll r = 1;
	while (y > 0){
		if (y % 2){
			r *= x;
			r %= p;
		}
		x *= x;
		x %= p;
		y /= 2;
	}
	return r;
}

ll bino(ll n, ll k)
{
	ll nf = 1, a = 1;

	for (ll i = n; i >= 1; i--){
		nf *= i;
		nf %= p;
	}
	for (ll i = k; i >= 1; i--){
		a *= i;
		a %= p;
	}
	for (ll i = n - k; i >= 1; i--){
		a *= i;
		a %= p;
	}

	return (nf*dqs(a, p - 2)) % p;


}

int main(void)
{
	ll n, k; std::cin >> n >> k;
	std::cout << bino(n, k);
	return 0;
}