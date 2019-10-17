#include <cstdio>

int tc, a, b, ans;

int main(void)
{
	scanf("%d", &tc);

	while (tc--) {
		scanf("%d%d", &a, &b);
		ans = 1;
		while (b--) {
			ans *= a;
			ans %= 10;
		}
		ans ? printf("%d\n", ans) : puts("10");
	}
	return 0;
}