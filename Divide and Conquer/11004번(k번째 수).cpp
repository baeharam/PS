#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

std::vector<int> a;

int main(void)
{
	int n, k; std::cin >> n >> k;
	int value;
	for (int i = 0; i < n; i++) {
		scanf("%d", &value);
		a.push_back(value);
	}

	std::nth_element(a.begin(), a.begin() + k-1, a.end());

	std::cout << a[k - 1];
	return 0;
}