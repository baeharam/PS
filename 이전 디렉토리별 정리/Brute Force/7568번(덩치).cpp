#include <cstdio>

int size[51][3];

int main(void)
{
	int n; scanf("%d", &n);

	for (int i = 1; i <= n; i++) scanf("%d %d", &size[i][0], &size[i][1]);

	for (int i = 1; i <= n; i++) {
		int greater = 0;
		for (int j = 1; j <= n; j++) {
			if (i != j && 
				(size[i][0] < size[j][0] && size[i][1] < size[j][1])) greater++;
		}
		size[i][2] = greater;
	}

	for (int i = 1; i <= n; i++) printf("%d ", size[i][2]+1);
	return 0;
}