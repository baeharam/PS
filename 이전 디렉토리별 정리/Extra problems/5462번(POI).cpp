#include <iostream>

int ps[2000 + 1][2000 + 1];
int score[2000 + 1];
int people[2000 + 1];
int num[2000 + 1];

int main(void)
{
	int n, t, p; std::cin >> n >> t >> p;

	// 각 사람의 ID가 푼 문제를 1로 못푼 문제를 0으로 초기화
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= t; j++){
			std::cin >> ps[i][j];
		}
	}

	// 위 배열을 바탕으로 점수 초기화
	for (int i = 1; i <= t; i++){
		for (int j = 1; j <= n; j++){
			if (ps[j][i] == 0) score[i]++;
		}
	}

	// 점수를 바탕으로 각 사람이 획득한 총 점수 초기화
	// 동시에 각 사람이 푼 문제 수 초기화
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= t; j++){
			if (ps[i][j] == 1){
				people[i] += score[j];
				num[i]++;
			}
		}
	}

	int rank = 1;

	// 아이디가 p인 경우를 제외하고 검사
	// 문제의 조건에 따라 순위 계산
	for (int i = 1; i <= n; i++){
		if (i != p){
			if (people[i] > people[p]) rank++;
			else if (people[i] == people[p]){
				if (num[i] > people[p]) rank++;
				else if (num[i] == num[p] && i < p) rank++;
			}
		}
	}

	std::cout << people[p] << ' ' << rank;

	return 0;
}