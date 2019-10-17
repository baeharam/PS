#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

typedef std::vector<std::pair<int, int>> vp;

vp ant;
std::deque<int> idList;
std::vector<int> fallList;

int main(void)
{
	int tc; std::cin >> tc;
	while (tc--) {
		int n, l, k, id, pos; std::cin >> n >> l >> k;
		while (n--) {
			std::cin >> pos >> id;
			// id순서를 기억하기 위해 idList에 저장한다.
			idList.push_back(id);
			// 방향(양수/음수)에 따라서 0 혹은 l과 현재위치와의 거리를 구해야 한다.
			id < 0 ? ant.push_back({ pos,id }) : ant.push_back({ l - pos,id });
		}
		// std::vector<std::pair>를 sort할 때는 처음 원소기준으로 한다.
		// 따라서 떨어질 때까지의 시간 기준으로 정렬한다.
		std::sort(ant.begin(), ant.end());

		for (int i = 0; i < ant.size(); i++) {
			// id의 앞,뒤를 먼저 기억해놓는다.
			int frontValue = idList.front(), backValue = idList.back();

			// 떨어지는 시간이 같은 경우
			if (i != ant.size() - 1 && ant[i].first == ant[i + 1].first) {
				// id가 더 작은 걸 먼저 저장한다.
				if (frontValue < backValue) {
					fallList.push_back(frontValue);
					fallList.push_back(backValue);
				}
				else {
					fallList.push_back(backValue);
					fallList.push_back(frontValue);
				}
				// 2개를 처리해주었기 때문에 덱에서 모두 pop해주고 i는 한번더 증가시킨다.
				idList.pop_back(); idList.pop_front(); i++;
			}
			// 일반적인 경우 id의 부호 즉, 방향에 따라서 어떤 id를 저장할 건지 결정한다.
			else if (ant[i].second < 0) {
				fallList.push_back(frontValue);
				idList.pop_front();
			}
			else {
				fallList.push_back(backValue);
				idList.pop_back();
			}
		}
		std::cout << fallList[k - 1] << '\n';

		// 초기화
		ant.clear();
		idList.clear();
		fallList.clear();
	}
	return 0;
}