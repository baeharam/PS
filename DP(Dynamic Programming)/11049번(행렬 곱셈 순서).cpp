// 연쇄 행렬 곱셈 알고리즘
// 곱셈순서에 따라서 곱셈 횟수가 달라질 수 있다.
// 따라서 그 곱셈 순서를 dp를 이용해 구하는 방법론이 연쇄행렬곱셈 알고리즘이다.
// m[i,j] = 0 (i=j)
// m[i,j] = min{m[i,k]+m[k+1,j]+p(i-1)p(k)p(j)} (i<j)

#include <cstdio>

int m[501][501]; // 행렬 곱셈에 따른 minimum cost i~j까지
int p[501]; // 행렬의 최종 크기를 담기 위한 배열
int k_position[501][501]; // 괄호로 분리되는 위치를 기억하기 위한 배열.

int main(void)
{
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) m[i][i] = 0; // i~i까지는 곱하지 않기 때문에 cost가 0이다.
	int r, s; // r x s 행렬
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &r, &s);
		p[i] = s;
		if (!p[0]) p[0] = r;
	}
	
	for (int chain = 2; chain <= n; chain++) {
		for (int i = 1; i <= n - chain + 1; i++) {
			int j = i + chain - 1;
			m[i][j] = 2100000000; // minimum cost를 찾기 위해서 매우 큰값으로 초기화
			for (int k = i; k <= j - 1; k++) {
				//printf("%d부터 %d까지, %d부터 %d까지의 최소비용\n", i, k, k + 1, j);
				//printf("p[i-1] : %d, p[k] : %d, p[j] : %d\n", p[i-1], p[k], p[j]);
				int temp_min = m[i][k] + m[k + 1][j] + p[i-1] * p[k] * p[j];
				if (temp_min < m[i][j]) {
					m[i][j] = temp_min;
					k_position[i][j] = k;
				}
			}
		}
	}
	printf("%d", m[1][n]);
	return 0;
}