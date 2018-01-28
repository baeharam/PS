#include <iostream>

// while(true)를 쓰지 않기 위함
const int flag = 123457;

// 최댓값 설정
const int max = 2 * 123456;

int main(void)
{
	// C의 stream과 sync를 맞추지 않아서 속도 업!
	std::ios_base::sync_with_stdio(false);

	int n = flag;

	while (n){
		std::cin >> n; if (!n) break;
		int num = 0; // 소수의 개수

		// 에라토스테네스의 체를 이용하기 위한 bool 배열
		// 숫자 그대로를 index로 사용
		bool eratos[max + 1] = { false };
		for (int i = 2; i <= 2 * n; i++){
			if (!eratos[i]){
				if(i>n) num++;
				for (int j = i + i; j <= 2 * n; j += i) eratos[j] = true;
			}
		}
		std::cout << num << '\n';
	}

	return 0;
}