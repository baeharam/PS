#include <cstdio>
#include <algorithm>

int main(void)
{
	int dwarf[9], sum = 0;
	for (int i = 0; i < 9; i++) {
		scanf("%d", &dwarf[i]);
		sum += dwarf[i];
	}

	std::sort(dwarf, dwarf + 9);

	int k1, k2;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (sum - dwarf[i] - dwarf[j] == 100) {
				k1 = i; k2 = j;
				break;
			}
		}
	}
	dwarf[k1] = -1; dwarf[k2] = -1;
	for (int i = 0; i < 9; i++) if (dwarf[i] != -1) printf("%d\n", dwarf[i]);
	return 0;
}