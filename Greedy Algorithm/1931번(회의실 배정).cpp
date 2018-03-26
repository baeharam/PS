#include <cstdio>
#include <algorithm>

// 각 회의는 시작시간과 끝시간이 있음
struct Meet {
	int begin;
	int end;
};

Meet m[100005]; // 회의의 수는 최대 10만개

/*
1. 끝나는 시간이 빠른 회의부터 추가한다. (남는 시간이 많으니까)
2. 끝나는 시간이 같을 경우, 시작시간이 빠른 회의부터 추가한다.
*/
bool cmp(const Meet& m1, const Meet& m2) {
	return (m1.end == m2.end) ? (m1.begin < m2.begin) : (m1.end < m2.end);
}

int main(void)
{
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d %d", &m[i].begin, &m[i].end);
	std::sort(m, m + (n + 1), cmp); // 위의 cmp함수 기준으로 sorting

	// 끝나는 시간 기준으로 정렬됬으니까 구조체 배열의 첫번째 end는 제일 빨리 끝나는 시간
	// time에 초기화 시키고 회의를 1번 했으니까 num은 1.
	int time = m[1].end;
	int num = 1;

	for (int i = 2; i <= n; i++) {
		// time이 다음에 시작할 회의의 시간보다 같거나 작으면 회의를 할 수 있으므로 num증가하고
		// 끝나는 시간은 현재 진행한 회의의 끝나는 시간으로 다시 설정.
		if (time <= m[i].begin) {
			num++;
			time = m[i].end;
		}
	}


	printf("%d", num);
	return 0;
}