#include <cstdio>
#include <algorithm>
using namespace std;

int rope[100005], n, m;

int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &rope[i]);

	sort(rope, rope + n);
	
	for (int i = 0; i < n; i++) {
		m = std::max(m, rope[i] * (n - i));
	}
	printf("%d", m);

	return 0;
}