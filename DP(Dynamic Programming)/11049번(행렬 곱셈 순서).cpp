// 연쇄 행렬 곱셈 알고리즘
// 곱셈순서에 따라서 곱셈 횟수가 달라질 수 있다.
// 따라서 그 곱셈 순서를 dp를 이용해 구하는 방법론이 연쇄행렬곱셈 알고리즘이다.
// m[i,j] = 0 (i=j)
// m[i,j] = min{m[i,k]+m[k+1,j]+p(i-1)p(k)p(j)} (i<j)

#include <cstdio>

int m[501][501]; // 행렬 곱셈에 따른 minimum cost i~j까지
int p[501]; // 행렬의 최종 크기를 담기 위한 배열
int k_position[501][501]; // 괄호로 분리되는 위치를 기억하기 위한 배열.

void PrintOptimalParen(int s[][501], int i, int j)
{
	if (i == j) printf("A%d", i);
	else {
		printf("(");
		PrintOptimalParen(s, i, s[i][j]);
		PrintOptimalParen(s, s[i][j] + 1, j);
		printf(")");
	}
}

int main(void)
{
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) m[i][i] = 0; // i~i까지는 곱하지 않기 때문에 cost가 0이다.
	int r, s; // r x s 행렬
	// 처음을 제외한 모든 곱해지는 값은 column이다.
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &r, &s);
		p[i] = s;
		// 처음만 row로 설정해준다.
		if (!p[0]) p[0] = r;
	}
	
	// 1. n개의 행렬을 곱한다고 하면 그 안에서 [1,k]와 [k+1,n]의 임의의 범위로 나눌 수 있고.
	// 행렬을 곱하는 개수는 2개부터 n개를 곱하는 경우가 있다.
	for (int chain = 2; chain <= n; chain++) {
		// 2. 몇개의 행렬을 곱하냐에 따라서 다음과 같이 곱할 수 있다.
		// EX) 2개의 행렬을 곱한다고 하면 (1,2),(2,3),(3,4)....(n-1,n) 이런 경우의 수들이 나온다.
		// 따라서 i가 1부터 n-chain+1인 이유가 여기에 있다. 몇개의 행렬을 곱하냐에 대해 생각해줘야 하기 때문!!
		for (int i = 1; i <= n - chain + 1; i++) {
			// 3. 정해진 i에 따라서 chain길이 만큼 곱해야 하므로 j가 그 역할을 한다. chain길이 만큼 끊어주는 것이다.
			int j = i + chain - 1;
			printf("곱하는 행렬의 개수 : %d, 어디까지? : %d\n-----------------------------------\n", chain, j);

			// 처음의 최소 비용은 없기 때문에 최소비용을 찾기 위해서 큰값으로 초기화 해주어야 한다.
			m[i][j] = 2100000000;

			// i부터 j까지 chain 길이만큼 곱하는데 그 곱하는데도 k를 기준으로 나뉘어질 수 있다.
			// EX) 1부터 3까지 곱하는 것은 (1,1),(2,3)과 (1,2),(3,3)으로 나뉜다.
			// 따라서 k의 범위는 i부터 j-1이 되는 것이다. k+1에 대해서 계산할 때가 있기 때문에 j-1까지..
			for (int k = i; k <= j - 1; k++) {
				printf("%d부터 %d까지, %d부터 %d까지의 최소비용\n", i, k, k + 1, j);
				printf("p[i-1] : %d, p[k] : %d, p[j] : %d", p[i-1], p[k], p[j]);
				int temp_min = m[i][k] + m[k + 1][j] + p[i-1] * p[k] * p[j];
				printf(", 최소비용 : %d\n", temp_min);
				printf("-------------------------------------------\n");
				if (temp_min < m[i][j]) {
					m[i][j] = temp_min;
					k_position[i][j] = k; // 곱셈이 최소비용을 내는 split하는 위치
				}
			}
		}
	}
	printf("최소 곱셈 횟수 : %d\n", m[1][n]);
	printf("어떻게 곱해야 하는가? : ");
	PrintOptimalParen(k_position, 1, n);
	return 0;
}