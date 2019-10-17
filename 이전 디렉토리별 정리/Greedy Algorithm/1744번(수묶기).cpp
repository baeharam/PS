#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> p, m;

int num[10001], n, ans;

// 음수와 양수를 각각 정렬해서 음수는 작은 것부터, 양수는 큰 것부터 묶었음
// 생각지 못한 경우 1. 음수와 0을 곱하는 것이 이득
// 생각지 못한 경우 2. 양수의 경우 더하기가 곱하기보다 큰 경우가 있을 수 있음


int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
		num[i] <= 0 ? m.push_back(num[i]) : p.push_back(num[i]);
	}

	sort(m.begin(), m.end());
	sort(p.begin(), p.end());
	
	int i = 0;
	while(i<m.size()) {
		if (i + 1 < m.size()) {
			ans += (m[i] * m[i + 1]);
			i += 2;
		}
		else {
			ans += m[i];
			i++;
		}
	}

	i = p.size() - 1;
	while (i >= 0) {
		if (i - 1 >= 0 && (p[i]*p[i-1] > p[i]+p[i-1])) {
			ans += (p[i] * p[i - 1]);
			i -= 2;
		}
		else {
			ans += p[i];
			i--;
		}
	}

	printf("%d\n", ans);
	return 0;
}