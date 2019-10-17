#include <cstdio>
#include <algorithm>
int a,b,n[100005], m[100005];

bool bs(int f)
{
	int l = 0, r = a - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (n[mid] == f) return true;
		else if (n[mid] < f) l = mid + 1;
		else if (n[mid] > f) r = mid - 1;
	}
	return false;
}

int main(void)
{
	scanf("%d", &a); for (int i = 0; i < a; i++) scanf("%d", &n[i]);
	scanf("%d", &b); for (int i = 0; i < b; i++) scanf("%d", &m[i]);

	std::sort(n, n + a);

	for (int i = 0; i < b; i++) bs(m[i]) ? puts("1") : puts("0");

	return 0;
}