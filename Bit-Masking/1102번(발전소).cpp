#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 1000000000;
int cost[17][17], dp[1 << 17], n, p, start;
string factory_state;

int fix(int state, int num)
{
	// 발전소가 p개만큼 켜져있다면 조건 만족이므로 0 리턴
	if (num == p) return 0;
	// 위 조건을 만족못하고 전부 꺼져있는 상황이라면 -1 리턴
	if (state == 0) return -1;

	// 메모이제이션
	int &ret = dp[state];
	if (ret != -1)return ret;

	// 최솟값을 위한 초기화
	ret = INF;
	for (int i = 0; i < n; i++) {
		// 켜져 있는 발전소 찾는다.
		if (state&(1 << i)) {
			for (int j = 0; j < n; j++) {
				// 같은 발전소면 다시
				if (i == j) continue;
				// 꺼져있는 발전소 찾는다.
				if ((state&(1 << j)) == 0)
					// 꺼져있는 걸 켠 상태를 넘기고 모두 켜질 때까지 계산
					ret = min(ret, fix(state | (1 << j), num+1) + cost[i][j]);
			}
		}
	}
	return ret;
}

int main(void)
{
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> cost[i][j];
	}
	cin >> factory_state >> p;
	
	// 현재 상태 확인 및 초기화, 그리고 몇개 켜져있는지 확인
	int cnt = 0;
	for (int i = 0; i < factory_state.size(); i++) {
		if (factory_state[i] == 'Y') {
			start |= (1 << i);
			cnt++;
		}
	}

	// p개 이상 켜져 있으면 비용 필요없음
	if (cnt >= p) puts("0");
	// p개 미만인데 0개 켜져있으면 발전소 가동 불가
	else if (cnt == 0) puts("-1");
	// 아니면 최소비용 출력
	else printf("%d", fix(start, cnt));
		
	return 0;
}