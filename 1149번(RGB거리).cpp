#include <iostream>

// 집을 칠하는 값을 저장한 배열
// 행은 최대 1000행, 열은 항상 3열
int cost[1000 + 1][3]; // n<=1000

// 최솟값을 구하는 변수
int min = 214546464;

// 사용자가 입력한 n을 공유하는 변수
int num;

// 가독성을 위해 enum으로 초기화 0,1,2
enum {R,G,B};

// 색칠하는 최솟값을 구하는 함수
// 칠하려는 색깔, 몇번째 집인지, 그 동안 계산한 값이 얼마인지를 인자로 받는다.
void RGB_min(int rgb, int nth, int sum)
{
	// 모든 집을 칠했다면 최솟값과 합을 비교해서 갱신하고 함수반환
	if (nth>num){
		if (min > sum) min = sum;
		return;
	}

	// 색깔 종류에 따라서 칠할 수 있는 색깔이 달라진다.
	switch (rgb){
		// 각각 sum을 업데이트시키고
		// R이면 G,B로 G면 R,B로 B이면 R,G로 이동시킨다.
	case R:
		sum += cost[nth][R];
		RGB_min(G,nth+1,sum); RGB_min(B,nth+1,sum);
		break;
	case G:
		sum += cost[nth][G];
		RGB_min(R, nth + 1, sum); RGB_min(B, nth + 1, sum);
		break;
	case B:
		sum += cost[nth][B];
		RGB_min(R, nth + 1, sum); RGB_min(G, nth + 1, sum);
		break;
	}
	
}


int main(void)
{
	int n; std::cin >> n; num = n;

	for (int i = 1; i <= n; i++)
		std::cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

	RGB_min(R, 1, 0); RGB_min(G, 1, 0); RGB_min(B, 1, 0);

	std::cout << min;

	return 0;
}