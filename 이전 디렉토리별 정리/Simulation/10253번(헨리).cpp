#include <iostream>

long long inputFraction[2];
long long unitFraction[2];

long long GCD(long long a, long long b)
{
	if (a < b) std::swap(a, b);
	while (b) {
		long long temp = a;
		a = b;
		b = temp % b;
	}
	return a;
}

long long LCM(long long a, long long b)
{
	return a * (b / GCD(a, b));
}

long long henryRepresentation()
{
	long long unitN = unitFraction[0], unitD = unitFraction[1]; // 단위분수의 분자,분모
	long long inputN = inputFraction[0], inputD = inputFraction[1]; // 입력분수의 분자,분모
	long long ans;

	while (true) {
		unitFraction[1]=inputFraction[1]=LCM(unitD, inputD); // 분모를 최소공배수로 통분

		// 통분한 것에 대해 분자도 맞춰준다.0
		unitFraction[0] = unitN * unitFraction[1] / unitD;
		inputFraction[0] = inputN * inputFraction[1] / inputD;

		if (unitFraction[0] == inputFraction[0]) {
			ans = inputFraction[1] / GCD(inputFraction[0], inputFraction[1]);
			break;
		}

		// 단위분수의 분자가 입력분수의 분자보다 작거나 같으면 빼주고 다시 처음부터 시작
		if (unitFraction[0] <= inputFraction[0]) {
			inputFraction[0] -= unitFraction[0];
			inputN = inputFraction[0]; inputD = inputFraction[1];

			if (inputN) unitD = inputD / inputN;
			else unitD++;
		}
		// 아니면 분모만 계속 증가시킨다.
		else unitD++;
		// 단위분수의 분자는 항상 1이기 때문에 초기화
		unitN = 1;
	}
	return ans;
}

int main(void)
{
	long long tc; std::cin >> tc;

	while (tc--) {
		unitFraction[0] = 1; // 단위분수의 분자는 1
		unitFraction[1] = 2; // 단위분수의 분모시작은 2
		std::cin >> inputFraction[0] >> inputFraction[1];
		std::cout << henryRepresentation() << '\n';
	}
	return 0;
}