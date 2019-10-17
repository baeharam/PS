#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
	int x;
	int y;
};
vector<Point> coor;

int dist(const Point &p1, const Point &p2)
{
	return (p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y);
}

bool cmp(const Point &p1, const Point &p2) {
	return p1.x < p2.x;
}

bool cmp2(const Point &p1, const Point &p2) {
	return p1.y < p2.y;
}

int closest(int s1, int s2)
{
	if (s1 == s2 - 1) return dist(coor[s1], coor[s2]);
	if (s1 == s2 - 2) return min(dist(coor[s1], coor[s1 + 1]), 
		min(dist(coor[s1 + 1], coor[s2]), dist(coor[s1], coor[s2])));
	int mid = (s1 + s2) / 2;
	int left = closest(s1, mid);
	int right = closest(mid + 1, s2);

	int d = min(left, right);

	vector<Point> candidate;
	for (int i = s1; i <= s2; i++) {
		int diff = coor[mid].x - coor[i].x;
		if (diff*diff <= d)
			candidate.push_back(coor[i]);
	}

	sort(candidate.begin(), candidate.end(), cmp2);
	
    /* x좌표가 모두 같고 y좌표만 다른 경우에 O(n^2)걸림 --> diff*diff<=d가 문제!
    d 이하가 아니라 d 미만으로 해야 했음. 왜일까?
    x와 y좌표가 모두 같은, 즉 같은 숫자가 들어올 경우 <=d로 하면 d가 0인데 계속 쓸데없는 갱신을 해주니까
    여전히 시간복잡도는 O(n^2) */
	for (size_t i = 0; i < candidate.size() - 1; i++) {
		for (size_t j = i + 1; j < candidate.size(); j++) {
			int diff = candidate[i].y - candidate[j].y;
			if (diff*diff < d)
				d = min(d, dist(candidate[i], candidate[j]));
			else
				break;
		}
	}
	return d;
}


int main(void)
{
	int n;
	scanf("%d", &n);
	coor.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &coor[i].x, &coor[i].y);
	}

	// x좌표 기준으로 정렬
	sort(coor.begin(), coor.end(), cmp);

	printf("%d\n", closest(0, n-1));
	return 0;
}