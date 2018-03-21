#include <iostream>

int main(void)
{

	int N, L; std::cin >> N >> L;
	int beginNum = -1, iter = -1;

	// L의 범위는 100까지니까 100까지만 구한다.
	for (int i = L; i <= 100; i++) {
		// L이 홀수이고 N이 L로 나누어 떨어지는 경우
		if (i % 2 != 0 && N%i == 0) beginNum = N / i - i / 2;
		// L이 짝수이고 N을 L로 나누었을 때의 나머지가 L을 2로 나눈 몫인 경우
		else if (i % 2 == 0 && N%i == i / 2) beginNum = N / i - (i / 2 - 1);
		// 시작숫자가 계산되었으면 반복횟수를 저장하고 나온다.	
		if (beginNum != -1) {
			iter = i;
			break;
		}
	}

	// 반복횟수가 저장되지 않았거나 시작숫자가 음수면 -1을 출력한다.
	if (iter == -1 || beginNum < 0) std::cout << -1;

	// 아니면 시작숫자부터 반복횟수만큼 연속된 숫자들을 출력한다.
	else {
		for (int i = 0; i < iter; i++)
			std::cout << beginNum + i << ' ';
	}

	return 0;
}