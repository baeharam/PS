#include <cstdio>
#include <algorithm>
using namespace std;

int main(void)
{
	int n; scanf("%d", &n);
	int *a = new int[n];
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n);
	for (int i = 1; i < n; i++) a[i] += a[i - 1];
	int sum = 0;
	for (int i = 0; i < n; i++) sum += a[i];
	printf("%d", sum);
	delete a;
	return 0;
}