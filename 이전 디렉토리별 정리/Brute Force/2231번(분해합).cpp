#include <cstdio>
#include <string>
int main(void)
{
	int n, ans = 0; scanf("%d", &n);

	for (int i = n / 2; i < n; i++) {
		std::string s = std::to_string(i);
		int sum = 0;
		for (int j = 0; j < s.size(); j++) sum += (s[j] - '0');
		if (i + sum == n) {
			ans = i;
			break;
		}
	}
	printf("%d", ans);
	return 0;
}