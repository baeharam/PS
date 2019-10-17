#include <cstdio>
#include <cstring>

long long dnum[1000005];

int main(void)
{
	memset(dnum, -1, sizeof dnum);
	long long i = 0, k = 0, n, jump, p, before;
	scanf("%lld", &n);
	bool isDecrease = true;

	while (k <= n) {
		p = i, before = -1, jump = 1;
		while (p) {
			if (p % 10 <= before) {
				isDecrease = false;
				jump *= 10;
			}
			before = p % 10;
			p /= 10;
		}
		if (!isDecrease) {
			i += jump;
			i = (i / jump)*jump;
			isDecrease = true;
		}
		else {
			dnum[k] = i;
			if (i == 9876543210) break;
			k++;
			i++;
		}
	}
	
	printf("%lld", dnum[n]);


	return 0;
}