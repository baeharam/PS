#include <iostream>

int main(void)
{
	int tc,n; std::cin >> tc;
	bool room[100 + 1]; // 5번방~100번방

	for (int i = 1; i <= 100; i++) room[i] = true;

	// 열려있음 : true (처음에 상범이가 다 열었다고 하자)
	// 다 여는 것이 첫번째이므로 2번방부터 검사
	// 닫혀있음 : false 

	while (tc--){
		std::cin >> n;
		for (int i = 2; i <= n; i++){
			for (int j = i; j <= n; j++){
				// i의 배수번 방만 검사한다.
				// 열려있으면 닫고 닫혀있으면 연다.
				if (j%i == 0)
					room[j] ? room[j] = false : room[j] = true;
			}
		}
		int whoCanRun = 0;
		for (int i = 1; i <= n; i++){
			// 열려있는 방만 도망갈 수 있다.
			if (room[i]) whoCanRun++;
			// 모든 방을 다시 연다 (초기화)
			room[i] = true;
		}
		std::cout << whoCanRun << '\n';
	}

	return 0;
}