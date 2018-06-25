#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int a[51], b[51];

int main()
{
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) scanf("%d", &b[i]);

	sort(a, a + n); sort(b, b + n,greater<int>());
	int sum = 0;
	for (int i = 0; i < n; i++) sum += a[i] * b[i];
	printf("%d", sum);
	return 0;
}