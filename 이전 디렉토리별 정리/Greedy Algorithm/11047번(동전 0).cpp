#include <cstdio>
using namespace std;

int coin[10];

int main(void)
{
	int n, k; scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%d", &coin[i]);

	int num = 0;

	for (int i = n - 1; i >= 0; i--) {
		num += k / coin[i];
		k %= coin[i];
		if (!k) break;
	}

	printf("%d", num);
	return 0;
}