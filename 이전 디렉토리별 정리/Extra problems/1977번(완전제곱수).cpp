#include <cstdio>
#include <cmath>

int main(void)
{
	int n, m, min = 2100000000, sum = 0; scanf("%d %d", &n, &m);
	for (int i = n; i <= m; i++) {
		double num = std::sqrt(i);
		if (std::fmod(num, 1.0) == 0) {
			sum += i;
			if (i < min) min = i;
		}
	}
	if (sum == 0) printf("-1");
	else printf("%d\n%d", sum, min);
	return 0;
}