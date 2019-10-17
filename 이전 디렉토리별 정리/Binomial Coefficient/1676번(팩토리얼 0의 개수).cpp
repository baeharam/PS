#include <iostream>

int main(void)
{
	int n; std::cin >> n;
	int zero = 0, temp;
	
	for (int i = n; i >= 1; i--){
		// 5를 포함하고 있으면 0의 개수 증가
		if (i % 5 == 0){
			temp = i;
			zero++;
			// 5로 나눈 몫도 5로 나눠진다는 것은
			// 5를 또 포함한다는 얘기이므로 0의 개수 다시 증가
			while ((temp / 5) % 5==0){
				zero++;
				temp /= 5;
			}
		}
	}

	std::cout << zero;

	return 0;
}