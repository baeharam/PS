#include <iostream>
#include <algorithm>
#include <cmath>

const int max = 8000 + 1;
const int negative = 4000;

int main(void)

{
	int n, minNum = 0,sum=0, maxNum = 0;
	std::cin >> n;
	int *List = new int[n];
	int Fre[max] = { 0 }; // 빈도수 배열
	// 음수 index를 사용하기 위함
	// p[-4000]=Fre[0]이고 p[4000]=Fre[8000]
	int *p = &Fre[negative];

	// 음수가 들어올 수도 있음
	for (int i = 0; i < n; i++){
		std::cin >> List[i];
		if (minNum > List[i]) minNum = List[i];
		if (maxNum < List[i]) maxNum = List[i];
		p[List[i]]++; sum += List[i];
	}


	// 오름차순 정렬
	std::sort(List,List+n);

	// 산술평균
	std::cout << std::floor(sum / static_cast<double>(n)+0.5) << std::endl;

	// 중앙값
	std::cout << List[n / 2] << std::endl;

	// 최빈값
	int freMax = 0, index; bool flag = false;

	// 최빈값 중 가장 큰 값을 찾고, 여러개인지 아닌지 확인
	for (int i = minNum; i <= maxNum; i++){
		if (freMax < p[i]){ flag = false; freMax = p[i]; index = i; }
		else if(freMax==p[i]) flag = true;
	}

	if (flag){
		for (int i = minNum; i <= maxNum; i++){
			if (flag && freMax == p[i]) { flag = false; }
			else if (!flag && freMax == p[i])
			{
				std::cout << i << std::endl;
				break;
			}
		}
	}
	else std::cout << index << std::endl;

	// 범위
	std::cout << List[n - 1] - List[0] << std::endl;

	// 메모리 해제
	delete[] List;

	return 0;
	
}