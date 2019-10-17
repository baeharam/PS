#include <cstdio>
#include <algorithm>
using namespace std;

int c[500000], num[500000], n, m;

bool bs(int l, int r, int f)
{
	if (l > r) return false;
	int mid = (l + r) / 2;
	if (f == c[mid]) return true;
	else if (f < c[mid]) return bs(l, mid - 1, f);
	else return bs(mid + 1, r, f);
}


int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &c[i]);
	
	scanf("%d", &m);
	for (int i = 0; i < m; i++) scanf("%d", &num[i]);

	sort(c, c + n);
	for(int i=0; i<m; i++) bs(0, n - 1, num[i]) ? printf("1") : printf("0");

	return 0;
}