#include <cstdio>
#include <algorithm>
using namespace std;

int x1, y, r1, x2, y2, r2, tc, d, sr, lr, m, p;


int main(void)
{
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d%d%d%d%d", &x1, &y, &r1, &x2, &y2, &r2);
		d = (x2 - x1)*(x2 - x1) + (y2 - y)*(y2 - y);
		sr = min(r1, r2); lr = max(r1, r2);
		m = (lr - sr)*(lr - sr);
		p = (lr + sr)*(lr + sr);

		if (d == 0) {
			if (m == 0) printf("-1");
			else printf("0");
		}
		else {
			if (m<d && p>d) printf("2");
			else if (p == d || m == d) printf("1");
			else if (p < d || m>d) printf("0");
		}
		printf("\n");
	}
	return 0;
}