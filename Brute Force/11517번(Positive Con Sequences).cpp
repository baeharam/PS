#include <cstdio>

int a, b, c, d, ans;

int main(void)
{
	while (true) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		if (a == -1 && b == -1 && c == -1 && d == -1) break;
		ans = -1;
		if (a == -1) {
			if (c - b == d - c && 2 * b - c >= 1) ans = 2 * b - c;
			else if (c%b == 0 && d%c == 0 && c / b == d / c && b*b / c >= 1 && b%(c/b)==0) ans = b * b / c;
		}
		else if (b == -1) {
			if (2 * (d - c) == (c - a)) ans = a + d - c;
			else if (d%c == 0 && c%a == 0 && (d / c) * (d / c) == (c / a)) ans = a * (d / c);
		}
		else if (c == -1) {
			if (2 * (b - a) == (d - b)) ans = 2 * b - a;
			else if (b%a == 0 && d%b == 0 && (b / a) * (b / a) == (d / b)) ans = b * b / a;
		}
		else if (d == -1) {
			if (b - a == c - b && 2 * c - b <= 10000) ans = 2 * c - b;
			else if (b%a == 0 && c%b == 0 && b / a == c / b && c*c / b <= 10000) ans = c * c / b;
		}
		printf("%d\n", ans);
	}
	return 0;
}