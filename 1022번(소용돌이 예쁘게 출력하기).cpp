#include <iostream>
#include <algorithm>

int spiral[5001][5001];

int main(void)
{
	int r1, c1, r2, c2;
	std::cin >> r1 >> c1 >> r2 >> c2;
	
	int i, j, begin_r1, begin_c1, end_r2, end_c2;

	// r1과 c1이 양수냐 음수냐에 따라서 (0,0)의 인덱스가 정해지는 방식이 다르고
	// 마지막에 출력할 때 어디서부터 어디까지 출력할 것인지가 다르기 때문에
	// 여기서 다 계산해준다. i,j는 처음에 (0,0)을 의미하는 인덱스 값으로 정해지며
	// begin_r1,begin_c1은 출력을 시작할 행과 열의 인덱스, end_r2,end_c2는 출력이 끝날 행과 열의 인덱스이다.
	if (r1 < 0) {
		i = r1 * -1;
		begin_r1 = 0;
		end_r2 = r2 - r1;
	}
	else {
		i = 0;
		begin_r1 = r1;
		r1 == 0 ? end_r2 = r2 - r1 : end_r2 = r2;
	}

	if (c1 < 0) {
		j = c1 * -1;
		begin_c1 = 0;
		end_c2 = c2 - c1;
	}
	else {
		j = 0;
		begin_c1 = c1;
		c1 == 0 ? end_c2 = c2 - c1 : end_c2 = c2;
	}

	// 소용돌이의 첫 시작은 1
	spiral[i][j] = 1;
	
	// 소용돌이가 오른쪽이나 위로 움직일 때 1,3,5,7...로 증가
	// 소용돌이가 왼쪽이나 아래로 움직일 때 2,4,6,8...로 증가
	int right_up = 1;
	int left_down = 2;

	// 소용돌이를 반복하는 횟수는 r1,c1,r2,c2중 절댓값으로 가장 큰 값을 구한뒤 1을 더해주는 형식
	int iter = std::max(std::max(std::abs(r1), std::abs(r2)), std::max(std::abs(c1), std::abs(c2))) + 1;

	// temp의 역할은 소용돌이를 계산할 때 인덱스가 음수가 되는 경우에 대해서 실제 spiral 배열에 넣을 수 없기 때문에
	// 임시변수로서 temp의 값을 소용돌이의 각 요소로 인식하고 계산하는 것.
	int temp = 1;

	// 위에서 계산한 iter만큼 반복한다.
	while(iter--){
		// 오른쪽
		for (int k = 0; k < right_up; k++) {
			// 일단 인덱스의 값은 업데이트시켜야 한다.
			j++;
			// 그리고 계산한 i,j값은 최소 (begin_r1, begin_r2)이고 최대 (end_r2,end_c2)이기 때문에 범위 점검을 해준 뒤
			// 적합하면 temp를 더해주고 temp에 이전값을 저장해준다.
			if (i>=begin_r1 && j>=begin_c1 && i<=end_r2 && j <=end_c2) {
				spiral[i][j] = temp + 1;
				temp = spiral[i][j];
			}
			// 이 부분이 인덱스가 범위를 초과한 부분으로 temp의 값을 증가시킴으로 소용돌이를 계속 만드는 역할을 한다.
			else temp++;
		}
		// 위쪽
		for (int k = 0; k < right_up; k++) {
			i--;
			if (i >= begin_r1 && j >= begin_c1 && i <= end_r2 && j <= end_c2) {
				spiral[i][j] = temp + 1;
				temp = spiral[i][j];
			}
			else temp++;
		}
		// 왼쪽
		for (int k = 0; k < left_down; k++) {
			j--;
			if (i >= begin_r1 && j >= begin_c1 && i <= end_r2 && j <= end_c2) {
				spiral[i][j] = temp + 1;
				temp = spiral[i][j];
			}
			else temp++;
		}
		// 아래쪽
		for (int k = 0; k < left_down; k++) {
			i++;
			if (i >= begin_r1 && j >= begin_c1 && i <= end_r2 && j <= end_c2) {
				spiral[i][j] = temp + 1;
				temp = spiral[i][j];
			}
			else temp++;
		}
		// 오른쪽/위쪽과 왼쪽/아래쪽이 2씩 증가하므로 2를 반복할 때마다 더해준다.
		right_up += 2;
		left_down += 2;
	}
	
	// 가장 길이가 긴 숫자를 고른다. (가장 큰 숫자랑 동일)
	int Longest = 0;
	for (int i = begin_r1; i <=end_r2; i++) {
		for (int j = begin_c1; j <=end_c2; j++) {
			if (Longest < spiral[i][j]) Longest = spiral[i][j];
		}
	}

	// 그 길이가 몇이나 되는지 구한다.
	int print_format = 1;
	while (Longest / 10) {
		Longest /= 10;
		print_format++;
	}

	// 출력파트
	for (int i = begin_r1; i <=end_r2; i++) {
		for (int j = begin_c1; j <=end_c2; j++) {
			// 위에서 구한 가장 긴 길이로 출력너비를 정한다.
			std::cout.width(print_format);
			// 너비를 다 채우지 못하는 숫자는 공백으로 채운다.
			std::cout.fill(' ');
			std::cout << spiral[i][j] << ' ';
		}
		std::cout << '\n';
	}

	return 0;
}