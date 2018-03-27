#include <cstdio>
#include <algorithm>

int A[51];
int B[51];
int P[51];

bool cmp(int a, int b)
{
	return a < b;
}

int main(void)
{
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
		B[i] = A[i];
	}

	std::sort(B, B + n, cmp);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (B[j] == A[i]) {
				P[i] = j;
				B[j] = -1;
				break;
			}
		}
	}
	for (int i = 0; i < n; i++) printf("%d ", P[i]);
	return 0;
}