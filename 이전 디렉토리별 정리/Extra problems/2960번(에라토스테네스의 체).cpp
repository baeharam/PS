#include <cstdio>

int e[10001];

int main(void)
{
	int n, k; scanf("%d%d", &n, &k);

	for (int i = 2; i <= n; i++) e[i] = i;
	
	int ans = 0;

	for (int i = 2; i <= n; i++) {
		for (int j = 1; i*j <= n; j++) {
			ans = e[i*j];
			e[i*j] = 0;
			if(ans!=0) k--;
			if (!k) {
				printf("%d", ans);
				return 0;
			}
		}
	}
}