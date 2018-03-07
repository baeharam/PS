#include <iostream>

int A[100][100];
int B[100][100];
int C[100][100];

void MatrixMultiplication(int n, int m, int k)
{
	for (int i = 0; i < n; i++) {
		for (int l = 0; l < k; l++) {
			for (int j = 0; j < m; j++) {
				C[i][l] += A[i][j] * B[j][l];
				//std::cout << i << "행 " << j << "열 * " << j << "행 * " << l << "열\n";
			}
			//std::cout << "------------------------------\n";
		}
	}

	for (int i = 0; i < n; i++) {
		for (int l = 0; l < k; l++) std::cout << C[i][l] << ' ';
		std::cout << '\n';
	}
}

int main(void)
{
	int n, m, k; std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			std::cin >> A[i][j];
	}
	std::cin >> m >> k;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++)
			std::cin >> B[i][j];
	}

	MatrixMultiplication(n, m, k);

	return 0;
}